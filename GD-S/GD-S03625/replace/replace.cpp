#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while (m--){
		string t[3];ans=0;
		cin>>t[1]>>t[2];
		int l1=t[1].size(),l2=t[2].size();
		if (l1!=l2){
			printf ("0\n");
			continue;
		}
		for (int j=1;j<=n;j++){
			int l=s[j][1].size();
			for (int i=0;i<l1-l+1;i++){
				for (int k=0;k<l;k++){
					if (s[j][1][k]!=t[1][i+k]) break;
					if (k==l-1){
						for (int d=0;d<l1;d++){
							if ((d<i||d>i+l-1)&&t[1][d]!=t[2][d]) break;
							if (d>=i&&d<=i+l-1&&s[j][2][d-i]!=t[2][d]) break;
							if (d==l1-1) ans++;
						}
					}
				}
				if (t[1][i]!=t[2][i]) break;
			}
		}	
		printf ("%d\n",ans);		
	}
	
	return 0;
}

