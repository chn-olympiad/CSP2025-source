#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int b[5005],book[5005],q=0,lk[5005];
long long bk[5005][5005],co;
long long sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i;j<=n;j++)sum+=a[i];
	}
	cout<<sum;
	//cout<<sum;
	return 0;

}
