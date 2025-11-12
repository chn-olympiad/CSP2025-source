#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010],n,k;
bool check(int mid){
	int sum = 0,left = 1;
	for(int i = 1;i <= n;i++){
		for(int j = left;j <= i;j++){
			if((int)(s[i]^s[j-1]) == k){
				sum++;
				if(sum >= mid){
					return true;
				}
				left = i+1;
				break;
			}
		}
	}
	if(sum >= mid){
		return true;
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>> n >> k;
	for(int i = 1;i <= n;i++){
		cin>> a[i];
		s[i] = (int)(s[i-1]^a[i]);
	}
	int l = 0,r = n;
	while(l < r){
		int mid = l+(r-l+1)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid-1;
		}
	}
	cout<< l;
	return 0;
}
