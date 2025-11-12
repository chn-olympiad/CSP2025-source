#include <bits/stdc++.h>
using namespace std;

const int N = 998244353;

int n,ans;
int a[5005];

bool pd(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum+=a[i];
	}
	if(sum > a[r]*2) return 1;
	return 0;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(pd(i,j)){
				ans++;
			}
		}
	}
	cout<<ans%N;
	return 0;
} 
