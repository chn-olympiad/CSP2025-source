#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10,M=2e6+10;
int n,q,ans;
string x,y,a[N],b[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y,ans=0;
		for(int k=1;k<=n;k++){
			int pos=0;
			while(pos!=x.npos){
				pos=x.find(a[k],pos);
				if(pos!=x.npos){
					if(x.substr(0,pos)+b[k]+x.substr(pos+a[k].size())==y)
					ans++;
					pos++;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}