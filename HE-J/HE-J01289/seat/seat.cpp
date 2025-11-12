#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=100000;
int n,m,nm,ans,k=1;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=1;i<=nm;i++)scanf("%d",&a[i]);
	ans=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[k]==ans){
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[k]==ans){
					cout<<j<<" "<<i;
					return 0;
				}
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

