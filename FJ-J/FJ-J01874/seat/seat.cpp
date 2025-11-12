#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000005];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
	int k=a[1];
	a[1]=1000;
	for(int i=2;i<=n*m+1;i++){
		if(a[i-1]>=k&&k>=a[i]){
			k=i-1;
			break;
		}
	}
	//cout<<k<<endl;
	if(1<=k%(2*n)&&k%(2*n)<=n){
		cout<<(k-1)/(2*n)*2+1<<" "<<k%(2*n);
	}else{ 
		cout<<(k-1)/(2*n)*2+2<<" "<<2*n-(k%2*n);
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
