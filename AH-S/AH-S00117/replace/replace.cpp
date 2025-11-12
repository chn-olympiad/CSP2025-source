#include<bits/stdc++.h>
using namespace std;
long long n,Q,w,ww,ans,len,ss;string s[200009][3],t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(Q--){
		cin>>t>>tt,len=t.size(),ans=0,w=0,ww=0,ss++;
		if(t.size()!=tt.size()){cout<<0<<endl;continue;}
		for(int i=0;i<len;i++){
			if(t[i]=='b'){w=i;break;}
			if(tt[i]=='b'){ww=i;break;}
			if(w!=0&&ww!=0) break;
		}
		for(int i=1;i<=n;i++){
			long long f=0,ff=0,L=s[i][1].size();
			for(int j=0;j<L;j++){
				if(s[i][1][j]=='b') f=j;
				if(s[i][2][j]=='b') ff=j;
				if(f!=0&&ff!=0) break;
			}
			if(abs(f-ff)==abs(w-ww)&&f<w&&L-f<len-w) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
