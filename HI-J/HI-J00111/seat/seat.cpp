#include<bits/stdc++.h>
using namespace std;
int n,m,t,nm,js;
int s[105];
int p[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for (int i=1;i<=nm;i++){
		cin>>s[++js];
	}
	t=s[1];
	sort(s+1,s+nm+1);
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for(int j=1;j<=n;j++){
				p[j][i]=s[js--];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				p[j][i]=s[js--];
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if(p[i][j]==t){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
