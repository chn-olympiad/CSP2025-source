#include<bits/stdc++.h>
using namespace std;
const int N = 2*10005;
long int n,m;
string a[N][5],b[N][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(long int i=1;i<=n;i++){
		for(long int j=1;j<=2;j++){
			cin >> a[i][j];
		}
	}
	for(long int i=1;i<=m;i++){
		for(long int j=1;j<=2;j++){
			cin >> b[i][j];
		}
	}
	for(long int i=1;i<=m;i++){
		long int lena = b[i][1].length(),lenb = b[i][2].length();
		string c="",d="";
		for(long int j=0;j<=max(lena,lenb);j++){
			if(b[i][1][j]!=b[i][2][j]){
				c += b[i][2][j];
				d += b[i][1][j];
			}
		}
		long int ans=0;
		for(long int j=1;j<=n;j++){
			if(a[j][1]==b[i][1]&&a[j][2]==b[i][2]){
				ans++;
			}
			if(a[j][1]==d&&a[j][2]==c){
				ans++;
			}
		}
		printf("%ld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
