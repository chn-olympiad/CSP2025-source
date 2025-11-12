#include <bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>maxn*2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

