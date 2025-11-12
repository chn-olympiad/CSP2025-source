#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
int n,q,st,ed,ans;
string s[200020],t[200020],a,b;
typedef long long ll;
ll base=8329,P=1e9+7;
ll ds[200020],dt[200020];
ll da[2000010],db[2000010];
ll pw[200020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=200000;i++)
		pw[i]=pw[i-1]*base%P;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		for(int j=0;j<s[i].size();j++){
			ds[i]=(ds[i]*base%P+(s[i][j]-'a'+1))%P;
			dt[i]=(dt[i]*base%P+(t[i][j]-'a'+1))%P;
		}
	}
	while(q--){
		cin>>a>>b;ans=0;
		st=1e9,ed=0;
		ll lsta=0,lstb=0;
		for(int i=0;i<a.size();i++){
			da[i]=(lsta*base%P+a[i]-'a'+1)%P;
			db[i]=(lstb*base%P+b[i]-'a'+1)%P;
			lsta=da[i],lstb=db[i];
			if(a[i]!=b[i]){
				if(st==1e9)
					st=i;
				ed=i;
			}
		}	
		for(int k=1;k<=n;k++){
			int len=s[k].size();
			if(st+len<=ed){
				continue;
			}
			int str=a.size();
			for(int i=max(0,ed-len+1);i<str;i++){
				int j=i+len-1;
				ll ss;
				if(i==0)
					ss=da[j];
				else
					ss=(da[j]+P-da[i-1]*pw[j-(i-1)]%P)%P;
				//cout<<k<<' '<<ds[k]<<' '<<ss<<endl;
				if(ss==ds[k]){
					//cout<<"YES";
					ll sa=(da[i-1]*pw[(str-1-(i-1))]%P+dt[k]*pw[str-1-j]%P+(da[str-1]+P-da[j]*pw[str-1-j]%P))%P;
					if(sa==db[str-1]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
