#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;
int n;
int a[N],da=-INT_MAX,sum,ans;
int b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			da=-INT_MAX;
			for(int l=i;l<=j;l++){
				da=max(da,a[l]);
			}
			if(b[j]-b[i-1]>2*da){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
