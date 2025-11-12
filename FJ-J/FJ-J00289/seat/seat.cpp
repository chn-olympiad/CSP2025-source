#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],ans[110],sx;
int sum=0,t;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);		
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++) cin>>ans[i];
	t=ans[1];
	sort(ans+1,ans+k+1);sx=k;
	for(int i=1;i<=n;){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[i][j]=ans[sx];
				sx-=1;}
		}
		else{
			for(int j=m;j>=1;j--){
				a[j][i]=ans[sx];
				sx-=1;}
		}
		i++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==t){
				cout<<i<<" "<<j;
				return 0;
			}
	return 0;
}
