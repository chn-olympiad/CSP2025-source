#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int s[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	int temp=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int tag=s[1];
	int ans=0;
	sort(s+1,s+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==tag){
			ans=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			if(j==1) a[i][j]=i,temp=0;
			else{
				temp=(temp+1)%2;
				if(temp==1) a[i][j]=a[i][j-1]+2*(n-i)+1;
				else a[i][j]=a[i][j-1]+2*i-1;
			}
			if(a[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
	}
}
