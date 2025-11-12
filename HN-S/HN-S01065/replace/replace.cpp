#include <bits/stdc++.h>
using namespace std;
const int N=5e6+5;
typedef unsigned long long ll;
int n,q;
char s[N];
ll d[2005][2],f[20005],sum[200005][2];

bool ok=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;j++)sum[i][0]=sum[i][0]*27+(s[j]-'a'+1);
		scanf("%s",s+1);
		len=strlen(s+1);
		for(int j=1;j<=len;j++)sum[i][1]=sum[i][1]*27+(s[j]-'a'+1);
	}
	f[0]=1;
//	sort(sum+1,sum+1+len,cmp);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]*27;
	while(q--){
		char s1[N],s2[N];
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1),l1=strlen(s2+1);
		int ans=0;
		int l=1,r=len;
		while(s1[r]==s2[r])l++;
		while(s1[r]==s2[r])r--;
		for(int i=1;i<=len;i++){
			d[i][0]=d[i-1][0]*27-(s1[i]-'a'+1);
			d[i][1]=d[i-1][1]*27-(s2[i]-'a'+1);
		}
	  for(int i=1;i<=len;i++){
			for(int j=1;j-i-1<=len;j++){
				ll s=d[j+i][0]-d[j][0]*f[i];
				ll ss=d[i+j][1]-d[j][1]*f[i];
				for(int k=1;k<=n;k++)
					if(sum[k][0]==s&&sum[k][1]==ss){
						ans++;
					}
				cout<<s<<" "<<ss<<"\n";
			}
		}
				
		
	}
	return 0;
}

