#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=205;
int n,q,m,ls[N];
char s[N][2][N],t[2][N],a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]+1>>s[i][1]+1;
		ls[i]=strlen(s[i][0]+1);
	}
	while(q--){
		int sum=0;
		cin>>t[0]+1>>t[1]+1;
		m=strlen(t[0]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) a[j]=t[0][j];
			int flag=0;
			for(int l=1;l+ls[i]-1<=n;l++){
				if(s[i][0][l]==t[0][l]){
					int f=1;
					for(int r=l;r<=l+ls[i]-1;r++) if(s[i][0][r]!=t[0][r]) f=0;
					if(f){
						for(int j=l;j<=l+ls[i]-1;j++) a[j]=s[i][1][j];
						int pd=1;
						for(int j=1;j<=m;j++) if(a[j]!=t[1][j]) pd=0;
						if(pd) flag=1;
					}
				}
			}
			sum+=flag;
		}
		cout<<sum<<endl;
	}
	return 0;
}

