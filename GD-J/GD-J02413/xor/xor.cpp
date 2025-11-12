#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long abc(int s,int b){
	long long waw=1048576,sum=0;
	for(;waw!=0;waw>>=1){
		if(s>=waw&&b<waw){
			s-=waw;
			sum+=waw;
		}
		else if(b>=waw&&s<waw){
			b-=waw;
			sum+=waw;
		}
		else if(b>=waw&&s>=waw){
			b-=waw;
			s-=waw;
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,qaq=1,ans=0,ikun=1;
	cin>>n>>k;
	for(int u=1;u<=n;u++){
		cin>>a[ikun];
		if(a[ikun]==k){
			ikun=1;
			ans++;
			continue;
		}
		for(int i=1;i<ikun;i++){
			a[i]=abc(a[i],a[ikun]);
			if(a[i]==k){
				ikun=0;
				ans++;
				break;
			}
		}
		ikun++;
	}
	cout<<ans<<endl;
	return 0;
}
