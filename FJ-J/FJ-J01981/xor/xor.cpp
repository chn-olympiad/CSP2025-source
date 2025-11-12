#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500040],b[500040][15],ans = 0,mx = 0;
void bin(long long x,long long y){
	long long sum = 1,sumt = 1;
	while(sum < x){
		sum *= 2;
		if(sum >= x){
			sumt++;
		}
	}
	mx = max(mx,sumt);
	for(int j = sum;j <= 1;j/2){
		if(x > sum){
			x -= sum;
			b[y][sumt]++;
		}
		sumt--;
	}
}
long long s(long long x,long long y){
	long long cnt = 0,cntl = 1;
	for(int r = 1;r <= mx;r++){
		cnt += (b[r][y]-b[r][x])*cntl;
		cntl *= 2;
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		bin(a[i],i);
	}
	if(k == 0){
		int w;
		for(int i = 2;i <= n;i+2){
			w += n-i+1;
		}
		cout<<w;
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(s(i,j) == k){
					ans++;	
				}
			}
		}
		cout<<ans;
	}
}
