#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
string t1,t2;
int n,q,ans;
int l[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		int len=t1.size();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=len-l[i];j++){
				int cnt=0;
				while(cnt<=l[i]&&t1[j+cnt]==s1[i][cnt]) cnt++;
				if(cnt<l[i]) continue;
				string ts=t1;
				for(int t=0;t<l[i];t++) ts[t+j]=s2[i][t];
				//cout<<ts<<" "<<i<<"\n";
				if(ts==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}