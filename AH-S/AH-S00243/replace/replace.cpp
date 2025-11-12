#include<bits/stdc++.h>
using namespace std;
int n,q;
string s,s2;
int th[200005],th2[200005],tt[200005],tt2[200005],lt,wt,lt2,wt2,ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s2;
		th2[i]=s.length();
		tt2[i]=s2.length();
		for(int j=0;j<th2[i];j++)if(s[i]=='b')th[i]=j;
		for(int j=0;j<tt2[i];j++)if(s2[i]=='b')tt[i]=j;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s>>s2;
		lt=s.length();
		lt2=s2.length();
		for(int j=0;j<lt;j++)if(s[i]=='b')wt=j;
		for(int j=0;j<lt2;j++)if(s2[i]=='b')wt2=j;
		for(int j=1;j<=n;j++){
			if(wt-wt2==th[j]-tt[j]&&wt>=th[j]&&th2[j]-th[j]<=lt-wt)ans++;
		}
		cout<<ans;
	}
	return 0;
}
