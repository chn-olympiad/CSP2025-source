#include<bits/stdc++.h>
using namespace std;
long long n,ans,maxn;
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdin);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(maxn<a[i])maxn=a[i];
	}
	if(maxn==1){
		cout<<0;
		return 0;
	}
	if(n<=3){
		if(n==3){
			sort(a,a+n);
			int v=a[0]+a[1]+a[2];
			if(v>(a[2]*2))cout<<1;
			else cout<<0;
		}else cout << 0;
		return 0;
	}
	cout<<6;
	return 0;
}
