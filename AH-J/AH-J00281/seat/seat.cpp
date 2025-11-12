#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[105];
int s[105][105];
int i=1,j=1;
int ans;
bool cmp(int a,int b){
  if(a>b)return true;
  else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++)cin>>a[i];
	ans=a[0];
	sort(a,a+m*n+2,cmp);
	while(j<=m){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				s[i][j]=a[sum++];
				if(s[i][j]==ans){
				cout<<j<<" "<<i<<endl;
				return 0;
			    }
			}
		}
		else{
			for(int i=n;i>=1;i--){
				s[i][j]=a[sum++];
				if(s[i][j]==ans){
				cout<<j<<" "<<i<<endl;
				return 0;
			    }
			}
		}
		j++;
	}
	return 0;
}
