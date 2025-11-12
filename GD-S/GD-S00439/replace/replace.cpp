#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string s[N],ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	string x,xx,y="",yy="";
	while(q--){
		cin>>x>>xx;
		ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]==xx[i]) continue;
			y=x[i],yy=xx[i];
			while(x[i+1]!=xx[i+1]){
				i++;
				y+=x[i],yy+=xx[i];
			}
			break;
		}
		for(int i=1;i<=n;i++){
			if((s[i]==x&&ss[i]==xx)||(s[i]==y&&ss[i]==yy)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
