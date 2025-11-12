#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int id=1;
	int i=1,j=1;// i 列 j 行 
	while(1){
		if(a[id]==ans){
			cout<<i<<" "<<j<<endl;
			return 0;
		}
		if(i%2==1){
			j++;
		}
		else j--;
		if(i%2==1 && j==n+1){
			i++;
			j=n;
		}
		if(i%2==0 && j==0){
			i++;
			j=1;
		}
		id++;
	}
}