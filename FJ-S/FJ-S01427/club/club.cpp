#include<bits/stdc++.h>
using namespace std;
struct perr1{
	int a,b,c,va;
}na[100005];
int n,T; 
bool cmp(perr1 x,perr1 y){
	return x.va>y.va;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>na[i].a>>na[i].b>>na[i].c;
			na[i].va=max(na[i].a,max(na[i].b,na[i].c))-((na[i].a+na[i].b+na[i].c)-max(na[i].a,max(na[i].b,na[i].c))-min(na[i].a,min(na[i].b,na[i].c)));
		}
		sort(na+1,na+n+1,cmp);
		int ca=0,cb=0,cc=0;
		for(int i=1;i<=n;i++){
		//	cout<<ans<<endl;
			int maxx=max(na[i].a,max(na[i].b,na[i].c));
			if(na[i].a==maxx&&ca<=n/2-1){
				ans+=na[i].a;
				ca++;
				continue;
			}
			if(na[i].b==maxx&&cb<=n/2-1){
				ans+=na[i].b;
				cb++;
				continue;
			}
			if(na[i].c==maxx&&cc<=n/2-1){
				ans+=na[i].c;
				cc++;
				continue;
			}
			ans+=((na[i].a+na[i].b+na[i].c)-max(na[i].a,max(na[i].b,na[i].c))-min(na[i].a,min(na[i].b,na[i].c)));
		//	cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
