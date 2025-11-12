#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int tlen=t1.size(),ans=0;
		for(int i=1;i<=n;i++){
			int len=s1[i].size();
			if(len>tlen) continue;
			for(int j=0;j+len-1<=tlen;j++){
				int fl1=1,fl2=1;
				for(int k=0;k<j;k++) if(t1[k]!=t2[k]) fl1=0;
				for(int k=j+len;k<tlen;k++) if(t1[k]!=t2[k]) fl2=0;
				for(int k=j;k<=j+len-1;k++){
					if(t1[k]!=s1[i][k]){fl1=0;break;}
					if(t2[k]!=s2[i][k]){fl2=0;break;}
				}
				if(fl1&&fl2) ans++;
			}
		} 
		cout<<ans<<"\n";
	}
 	return 0;
}

