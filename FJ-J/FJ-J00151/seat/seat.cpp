#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,m;
int a[2500];
int v[100][100];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int flag=0;
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(k>m*n){
					flag=1;
					break;
				}
				v[j][i]=a[k];
				k++;
			}
			if(flag==1) break;
		}
		else{
			for(int j=n;j>=1;j--){
				if(k>m*n){
					flag=1;
					break;
				}
				v[j][i]=a[k];
				k++;
			} 
			if(flag==1) break;
		}
	}
	flag=0;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==ans){
				x=i;
				y=j;
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	}
	cout<<y<<" "<<x;
	return 0;
} 
