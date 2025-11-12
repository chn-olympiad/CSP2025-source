#include<bits/stdc++.h>
using namespace std;
int s[110];
int a[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int tot=n*m;
	for(int i=1; i<=tot; i++) cin>>s[i];
	int r=s[1],cnt=tot;
	sort(s+1,s+tot+1);
	for(int i=1; i<=m; i++){
		if(i%2==1)
			for(int j=1; j<=n; j++){
				a[j][i]=s[cnt];
				cnt--;
			}
		else{
			for(int j=n; j>=1; j--){
				a[j][i]=s[cnt];
				cnt--;
			}
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
	return 0;
}
