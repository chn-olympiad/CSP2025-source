#include<bits/stdc++.h>
using  namespace std;
bool dx(int a,int b){
	return a>b;
}
struct ans{
	int b,lb;
};

int n,num,b1,c1,d1,t,p,q,r;
ans x[100001];
ans y[100001];
ans z[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=0;j<n-1;j++){
			cin>>x[j].b>>y[j].b>>z[j].b;
			x[j].lb=y[j].lb=z[j].lb=i;
		}
		sort(x,x+n,dx);
		sort(y,y+n,dx);
		sort(z,z+n,dx);
		for(int k=0;k<=n-1;k++){
			if(x[p].b>=z[r].b&&x[p].b>=y[q].b&&x[p].lb!=z[r].lb&&x[p].lb!=y[q].lb&&b1<=n/2){
				p++;
				b1++;
				num+=x[p].b;
			}
			else{
				if(x[p].b>=z[r].b&&x[p].b>=y[q].b&&x[p].lb==z[r].lb&&x[p].lb!=y[q].lb&&b1<=0){
				p++;
				r++;
				b1++;
				num+=x[p].b;
				}	
				if(x[p].b>=z[r].b&&x[p].b>=y[q].b&&x[p].lb==z[r].lb&&x[p].lb==y[q].lb&&b1<=n/2){
				p++;
				r++;
				q++;
				b1++;
				num+=x[p].b;
				}
				if(x[p].b>=z[r].b&&x[p].b>=y[q].b&&x[p].lb!=z[r].lb&&x[p].lb==y[q].lb&&b1<=n/2){
				p++;
				q++;
				b1++;
				num+=x[p].b;
				}
			}
			
		}
		cout<<num<<endl;
	}
	
	return 0;
}

