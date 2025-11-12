#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
ll a[N],k;int n,cnt,t,betw[N][N],lastr;
int Sum(int l,int r){
	if(l==r)return a[l];
	int sum=a[l];
	for(int i=l+1;i<=r;i++)sum=sum xor a[i];
	return sum;
}
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i<=lastr)continue;
		for(int j=i;j<=n;j++)
			if(Sum(i,j)==k){cnt++;lastr=j;break;}
	}
	cout<<cnt<<endl;
	return 0;
}
