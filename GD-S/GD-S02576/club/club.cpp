# include <bits/stdc++.h>
using namespace std;
int t,n,num1,num2,num3,tot,k;
struct no{
	int a,b,c,id,cz;
};
no g[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t){
	    priority_queue<int> tk;
		t--;
		scanf("%d",&n);
		num1=0; num2=0; num3=0;
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].c);
			if (g[i].a==max(max(g[i].a,g[i].b),g[i].c)){
				g[i].id = 1;
				num1++;
				g[i].cz = g[i].a - max(g[i].b,g[i].c);
			} 
			else if (g[i].b==max(max(g[i].a,g[i].b),g[i].c)){
				g[i].id = 2;
				num2++;
				g[i].cz = g[i].b - max(g[i].a,g[i].c);
			} 
			else{
				g[i].id = 3;
				num3++;
				g[i].cz = g[i].c - max(g[i].b,g[i].a);
			} 
		}
		if (num1==max(max(num1,num2),num3)){
			k=1;
		}
		else if (num2==max(max(num1,num2),num3)){
			k=2;
		}
		else k=3;
		int p = 1;
		tot = 0;
		num1 = 0;num2=0;num3=0;
		while(p<=n){
		//cout<<g[p].id<<" "<<tot<<endl;
		    		
			if(g[p].id==1){
				num1++;
				tot+=g[p].a;
				if (k==1&&num1<=n/2){
					tk.push(g[p].cz*-1);
				}
			} 
			if(g[p].id==2){
				num2++;
				tot+=g[p].b;
				if (k==2&&num2<=n/2){
					tk.push(g[p].cz*-1);
				}
			}
			if(g[p].id==3){
				num3++;
				tot+=g[p].c;
				if (k==3&&num3<=n/2){
					tk.push(g[p].cz*-1);
				}
			}
			//cout<<tk.top()<<endl;
			if (num1>n/2&&g[p].id==1){
				if (g[p].cz*-1<tk.top()){
					tot-=tk.top()*-1;
					tk.pop();
					tk.push(g[p].cz*-1);
				}
				else tot-=g[p].cz;
			}
			if (num2>n/2&&g[p].id==2){
				if (g[p].cz*-1<tk.top()){
					tot-=tk.top()*-1;
					tk.pop();
					tk.push(g[p].cz*-1);
				}
				else tot-=g[p].cz;
			}
			if (num3>n/2&&g[p].id==3){
				if (g[p].cz*-1<tk.top()){
					//cout<<tot;
					tot-=tk.top()*-1;
					tk.pop();
					//cout<<" "<<tot<<endl;
					tk.push(g[p].cz*-1);
				}
				else tot-=g[p].cz;
			}
			p++;
		}
		cout<<tot<<endl;
	}
	return 0;
} 
