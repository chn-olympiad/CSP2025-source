#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][5],t[200005][5],sis[200005],sit[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int j=0;
		while(s[i][1][j]==s[i][2][j])
			j++;
		int k=s[i][1].size()-1;
		while(s[i][1][k]==s[i][2][k])
			k--;
		int top=1;
		for(int l=j;l<=k;l++){
			s[i][3][top]=s[i][1][l];
			s[i][4][top]=s[i][2][l];
			top++;
		}
		sis[i]=k-j+1;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		int j=0;
		while(t[i][1][j]==t[i][2][j])
			j++;
		int k=t[i][1].size()-1;
		while(t[i][1][k]==t[i][2][k])
			k--;
		int top=1;
		for(int l=j;l<=k;l++){
			t[i][3][top]=t[i][1][l];
			t[i][4][top]=t[i][2][l];
			top++;
		}
		sit[i]=k-j+1;
		for(int l=1;l<=n;l++){
			int num=0;
			if(sis[l]==sit[i])
				for(int m=1;m<=k-j+1;m++){
					if(s[l][3][m]==t[i][3][m]&&s[l][4][m]==t[i][4][m])
						num++;
					else break;
				}
				if(num==k-j+1)ans++;
		}
		cout<<ans<<endl;
	}
		
	return 0;
}
