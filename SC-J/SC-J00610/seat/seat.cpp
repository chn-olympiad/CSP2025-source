#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,r,k,sum,x2,y2,jk;
int a[1005],s[100][100];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
		for(int j=1;j<=n;j++){
			sum++;
			s[i][j]=a[sum];
			if(a[sum]==r){
				x2=i;
				y2=j;
			}
		}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
			sum++;
			s[i][j]=a[sum];
			if(a[sum]==r){
				x2=i;
				y2=j;
			}
		}
		}
	}
	cout<<x2<<" "<<y2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
