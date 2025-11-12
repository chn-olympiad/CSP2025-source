#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,q,hsh[200005][3],jc[5000005],sum[5000005];
string s[200005][3];
char c[5000005],c2[5000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=5000000;i++) jc[i]=jc[i-1]*61%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].size(),len2=s[i][2].size();
		for(int j=0;j<len;j++){
			(hsh[i][1]+=jc[j]*(s[i][1][j]-'a'+1)%mod)%=mod;
		}
		for(int j=0;j<len2;j++){
			(hsh[i][2]+=jc[j]*(s[i][2][j]-'a'+1)%mod)%=mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<hsh[i][1]<<" "<<hsh[i][2]<<endl;
//	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int l1=s1.size(),l2=s2.size();
		if(l1!=l2){cout<<"0\n";continue;}
		for(int i=0;i<l1;i++){
			sum[i]=(sum[i-1]+jc[i]*(s1[i]-'a'+1)%mod)%mod;
		}
//		for(int i=0;i<l1;i++) cout<<sum[i]<<" ";
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()>s1.size()) continue;
			int cnt=hsh[i][1],sz=s[i][1].size();
			for(int j=0;j<=l1-sz;j++){
				if(cnt==(sum[j+sz-1]-(j>0?sum[j-1]:0)+mod)%mod)
				{
					string pp=s1;
					int ind=-1;
					for(int k=j;k<=j+sz-1;k++){
						pp[k]=s[i][2][++ind];
					}
//					for(int k=0;k<l1;k++) cout<<pp[k];
//					cout<<endl;
					if(pp==s2) ans++;
				}
				cnt=cnt*61%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
