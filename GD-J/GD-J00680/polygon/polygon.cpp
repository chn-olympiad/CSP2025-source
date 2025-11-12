#include<bits/stdc++.h>
using namespace std;
const int INT=998244353;
long long n,ans;
int a[5010];
void pd(int x,int y){
	int cu=0,cu1=0;
	for(int i=x;i<=x+y-1;i++){
		cu1+=a[i];
		if(a[i]>cu){
			cu=a[i];
		}
	}
	if(cu*2<cu1){
		ans=(ans%INT+1)%INT;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=3;j+i-1<=n;j++){
			pd(i,j);
		}
	}
	ans=(ans%INT+(ans-1)%INT)%INT;
	cout<<ans;
	freopen("polygon.out","w",stdout);
}

