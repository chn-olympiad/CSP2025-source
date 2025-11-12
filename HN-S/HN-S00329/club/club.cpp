#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
int T,n,zh=0,m=3,ans=0;
int zh1=0,zh2=0,zh3=0,K[N];
struct node{
	int a,b,c;
}v[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		if(n==2){
			int a1,a2,a3,b1,b2,b3;
			cin>>b1>>b2>>b3;
			cin>>a1>>a2>>a3; 
			int u1=max(b1+a2,b1+a3);
			int u2=max(b2+a1,b2+a3);
			int u3=max(b3+a1,b3+a2);
			cout<<max(u1,max(u2,u3));
		}
		else{
			for(int i=1;i<=n;i++) {
				cin>>v[i].a>>K[i]>>v[i].c;
			}
			zh=n/2;
			sort(K+1,K+n+1);
			for(int i=n;i>=zh;i--){
				ans+=K[i];
			}
			cout<<ans<<endl; 
		}
	}
	return 0;
}
