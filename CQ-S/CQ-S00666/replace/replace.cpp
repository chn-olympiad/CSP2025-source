#include<bits/stdc++.h>
using namespace std;
string st[1000005],ed[1000005];
int n,q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>st[i]>>ed[i];
	while(q--){
		string start,end;
		cin>>start>>end;
		int ans=0;
		for(int i=0;i<start.size();i++){
			for(int j=1;j<=n;j++){
				int pos1=i,pos2=0;
				while(pos1<start.size()&&pos2<st[j].size()&&start[pos1]==st[j][pos2])pos1++,pos2++;
				if(pos2>=st[j].size()){
					string xx=start.substr(0,i);
					string yy=start.substr(pos1);
					string tmp=xx+ed[j]+yy;
					if(tmp==end)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
