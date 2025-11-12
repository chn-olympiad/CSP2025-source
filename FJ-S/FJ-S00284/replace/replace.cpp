// Wrong

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod=999999893, B=1145141;

string s1[200009], s2[200009];
int h1[200009], h2[200009], f1[200009];

char t1[1000009], t2[1000009];
int h3[1000009], h4[1000009], po[1000009];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	po[0]=1;
	for (int i=1; i<=1000000; i++)	po[i]=1ll*po[i-1]*B%mod;
	
	int n, q;
	scanf("%d%d", &n, &q);
	
	for (int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
		
		int j;
		for (j=0; j<s1[i].size() && s1[i][j]==s2[i][j]; j++)	;
		f1[i]=j+1;
		
		for (j=0; j<s1[i].size(); j++){
			h1[i]=(1ll*h1[i]*B+s1[i][j]-'a'+3)%mod;
			h2[i]=(1ll*h2[i]*B+s2[i][j]-'a'+3)%mod;
		}
	}
	
	while (q--){
		scanf("%s", t1+1);
		scanf("%s", t2+1);
		int len=strlen(t1+1);
		if (strlen(t2+1)!=len){
			puts("0");
			continue;
		}
		
		int f2, f3;
		for (f2=1; f2<=len && t1[f2]==t2[f2]; f2++)	;
		for (f3=len; f3 && t1[f3]==t2[f3]; f3--)	;
		
		for (int i=1; i<=len; i++){
			h3[i]=(1ll*h3[i-1]*B+t1[i]-'a'+3)%mod;
			h4[i]=(1ll*h4[i-1]*B+t2[i]-'a'+3)%mod;
		}
		
		int ans=0;
		for (int i=1; i<=n; i++){
			int l=f2-f1[i]+1, r=s1[i].size()-f1[i]+f2;
			if (1<=l && l<=len && 1<=r && r<=len && f3<=r
				&& h1[i]==((h3[r]-1ll*h3[l-1]*po[r-l+1])%mod+mod)%mod
				&& h2[i]==((h4[r]-1ll*h4[l-1]*po[r-l+1])%mod+mod)%mod)
					ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
