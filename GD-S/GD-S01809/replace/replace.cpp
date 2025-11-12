#include<bits/stdc++.h>
using namespace std;
struct r{
	string s,s1;
	long long l;
};
r a[200005];
long long n,q,ans;
int main(){	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].s1;
		a[i].l=a[i].s.size();
	}
	for(int i=1;i<=q;i++){
		string sq,sq1,x,y,z;
		cin>>sq>>sq1;
		ans=0;
		for(int i=1;i<=n;i++){
			int j=0,lq,lq1;
			lq=sq.find(a[i].s);
			y=sq.substr(0,lq)+a[i].s1+sq.substr(lq+a[i].l);
			if(y==sq1){
				ans++;
			}
			//cout<<y<<" ";
		}
		cout<<ans<<endl;
	}
	return 0;
}
