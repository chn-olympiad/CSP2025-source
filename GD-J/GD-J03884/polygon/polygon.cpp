#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[10000];

int s(int i,int k,int ad){
	int sans = 0;
	for(int j=i;j<n-k+1;j++){
		
		ad += a[j];
		if(k == 1){
			if(a[j]*2 < ad){
				sans += 1;
			}
		}
		else{
			sans += s(j+1,k-1,ad);
		}	
		
		ad -= a[j];
	}
	return sans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		ans += s(0,i,0);
		ans %= 998244353;
	}
	cout << ans;
	return 0;
	/*
	for(int i=0;i<6000){
		if(a[i]){
			
		}
	}
	*/
}
