#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,k;

long long yihuo(long long x,long long y){
	long long yu = x&y;
	long long huo = x|y,sums = 0;
	string jg = "",yu2 = "",huo2 = "";
	while(yu!=0 || huo!=0){
		yu2 += char(yu%2+48);
		huo2 += char(huo%2+48);
		yu /= 2;
		huo /= 2;
	}
	for(int i=0 ; i<yu2.size() ; i++){
		if(yu2[i] == huo2[i]) jg += '0';
		else jg += '1';
	}
	long long  po = 1;
	for(int i=0 ; i<jg.size() ; i++){
		sums += int(jg[i]-48)*po;
		po *= 2;
	}
	return sums;
}

bool check(long long x){
	long long start = 1;
	long long sums = 0;
	while(start <= n){
		if(sums == x) return true;
		long long jg = a[start];
		if(jg == k){
			sums++;
			start++;
			continue;
		}
		bool flag = 0;
		for(long long j=start+1 ; j<=n ; j++){
			jg = yihuo(jg,a[j]);
			if(jg == k){
				sums++;
				start = j+1;
				flag = 1;
				break;
			}
		}
		if(!flag) start++;
	}
	return sums >= x;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1 ; i<=n ; i++) cin >> a[i];
	long long left = 0,right = n;
	while(left <= right){
		long long mid = (left+right)/2;
		if(check(mid)) left = mid+1;
		else right = mid-1;
	}
	cout << right;
	return 0;
}
