#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int a[15][15];
int cmp(int a,int b){
	return a>b;
}
int main(
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int k=1;k<=n*m;k++){
		for(int j=1;j<=m;j++){
			if((k/n)%2==0&&(k%n)!=0){
				for(int i=1;i<=n;i++){
					a[i][j]=s[i];
					if(ans==a[i][j]){
						cout<<n<<" "<<m;
					}
				}
			}
			if((k/n)%2==1&&(k%n)==1){
				for(int i=n;i>=1;i--){
					a[i][j]=s[i];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==a[i][j])
			{
				cout<<n<<" "<<m;
				return 0;
			}
		}
	}
	return 0;
} 
