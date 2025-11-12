#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],maxn=-1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	int cnt=0;
	if(sum>maxn*2){
		cnt++;
	}
	cout<<cnt%998244353;
	return 0;
}
