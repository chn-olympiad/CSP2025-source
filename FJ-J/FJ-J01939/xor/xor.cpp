#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,maxx,minn = 999999;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		maxx = max(a[i],maxx);
		minn = min(a[i],minn);
	}
	if(k==0&& maxx ==1&&minn == 1){cout<<n/2;}
	else if(maxx ==1&&minn == 0){for(int i =1;i<=n;i++){if(a[i]==0){n--;}}cout<<n/2;}
	else{
		for(int i =1;i<=n;i++){
			int l =i,r = i,s = a[l],ss =0;
			while(r<=n){
			r++;
			if(s==k){ss++;s = 0;}
			s = s xor a[r];
			}
			sum = max(sum,ss);
		}cout<<sum;
	}
}