#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m;
int f1[4]={};
int mx=0;
struct j{
	int a,b,c,next,n1,m1;
	int maxx=0;
}num[20001];
void dfs(int dp,int f[4],int ans){
	if(dp==1){
		f[1]=0;
		f[2]=0;
		f[3]=0;
	}

	if(ans>mx){
		mx=ans;
	}
	cout<<num[dp].m1<<f[num[dp].m1]<<endl;
	if(f[num[dp].m1]<n/2){
		ans+=num[dp].maxx;
		f[num[dp].m1]++;

		if(dp>=n){
			if(ans>mx){
		mx=ans;
	}
		return ;
	}
		dfs(dp+1,f,ans);
		f[num[dp].m1]--;
		ans-=num[dp].maxx;
	}
	if(f[num[dp].n1]<n/2){
		ans+=num[dp].next;
		f[num[dp].n1]++;

		if(dp>=n){
			if(ans>mx){
		mx=ans;
	}
		return ;
	}
		dfs(dp+1,f,ans);
		return ;
	}return;
	
	
	
}
 int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int Q;
 	cin>>Q;
 	while(Q--){
 		mx=0;
 		cin>>n;
		m=n<<1;
		for(int i=1;i<=n;i++){
			cin>>num[i].a>>num[i].b>>num[i].c;
			if(num[i].a>=num[i].b){
				if(num[i].a>=num[i].c){
					num[i].maxx=num[i].a;
					num[i].m1=1;
					if(num[i].b>=num[i].c){
						num[i].next=num[i].b;
						num[i].n1=2;
					}else{
						num[i].next=num[i].c;
						num[i].n1=3;
					}
				}else{
					num[i].maxx=num[i].c;
					num[i].m1=3;
					if(num[i].b>=num[i].c){
						num[i].next=num[i].c;
						num[i].n1=3;
					}else{
						num[i].next=num[i].b;
						num[i].n1=2;
					}
				}
			}else{
				if(num[i].b>=num[i].c){
					num[i].maxx=num[i].b;
					num[i].m1=2;
					if(num[i].a>=num[i].c){
						num[i].next=num[i].a;
						num[i].n1=1;
					}else{
						num[i].next=num[i].c;
						num[i].n1=3;
					}
				}else{
					num[i].maxx=num[i].c;
					num[i].m1=3;
					if(num[i].a>=num[i].c){
						num[i].next=num[i].c;
						num[i].n1=3;
					}else{
						num[i].next=num[i].a;
						num[i].n1=1;
					}
				}
			}
			}dfs(1,f1,0);
			cout<<mx;
	 }

	}
  
