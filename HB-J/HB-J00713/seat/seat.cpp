#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110][110],b[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>b[i];
	}
	int ans=b[1];
	sort(b+1,b+cnt+1,cmp);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				sum++;
				a[i][j]=b[sum];
				if(a[i][j]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else if(i%2==1){
			for(int j=1;j<=m;j++){
				sum++;
				a[i][j]=b[sum];
				if(a[i][j]==ans){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
