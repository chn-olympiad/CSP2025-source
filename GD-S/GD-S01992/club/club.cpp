#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n;
struct Node{
	int c[5];
	int pos,mx=-1e9,sum;
	void input(){
		for(int i=1;i<=3;++i){
			cin>>c[i];
			sum+=c[i];
		}
	}
	void getmx(){
		mx=max({c[1],c[2],c[3]});
		if(c[1]==mx) pos=1;
		if(c[2]==mx) pos=2;
		if(c[3]==mx) pos=3; 
		if()
	}
}a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		cin>>n;
		for(int i=1;i<=n;++i){
			a[i].input();
		}
		int ans=0;
		if(n==2){
			for(int i=1;i<=2;++i){
				a[i].getmx();
				cout<<a[i].mx<<" "<<a[i].pos<<endl;
			}
			if(a[1].pos==a[2].pos){
				for(int i=1;i<=2;++i){
					
				}
				if(a[1].mx>a[2].mx){
					a[2].c[a[2].pos]=0;
					a[2].getmx();
				}
				else{
					a[1].c[a[1].pos]=0;
					a[1].getmx();
				}
			}
			ans=a[1].mx+a[2].mx;
		}
		else{
			for(int i=1;i<=n;++i){
				a[i].getmx();
			}
			for(int i=1;i<=n;++i){
				a[i].getmx();
			}
			for(int i=1;i<=n;++i){
				ans+=a[i].mx;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
