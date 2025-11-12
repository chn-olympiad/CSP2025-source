#include<bits/stdc++.h>
using namespace std;
int a[1005],b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	ans=a[0];
	sort(a,a+n*m,cmp);
	int i=1,j=1,num=0,z=0;
	while(i<=n){
		if(num>n*m)break;
		if(i<n&&z==0){
			b[i][j]=a[num];
			num++,i++;
		}
		else if(i>1&&z==1){
			b[i][j]=a[num];
			num++,i--;
		}
		else {
			b[i][j]=a[num];
			num++,j++;
			if(z==0)z=1;
			else z=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans)cout<<j<<" "<<i;
		}
	}
	return 0;
} 
