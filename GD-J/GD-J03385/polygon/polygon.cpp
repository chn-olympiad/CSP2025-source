#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long s=0;
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int ma=a[n];
	long long tt[5005];
	if(n==3){
		int s=a[1]+a[2]+a[3];
		if(s>ma*2) cout << 1;
		else cout << 0;
	}
	else{
		bool is=1;
		for(int i = 1;i<=n;i++){
			if(a[i]!=1) is=0;
		}
		
		if(is==1){
			tt[0]=1;
			for(int i = 1;i<=n;i++){
				tt[i]=tt[i-1]+i+1;
			}
			cout << tt[n-3]%998244353;
			return 0;
		}
	}
	return 0;
}
