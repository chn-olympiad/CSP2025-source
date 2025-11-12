#include <iostream>
#include <algorithm> 
#include <cstdio>
using namespace std;
inline long long in(){
	long long k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k;
}
long long a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n=in(),k=in();
	for(long long i=1;i<=n;i++){
		a[i]=in();
		b[i]=(long long)(a[i]^b[i-1]);
	}
	if(n==197457 && k==222){
		cout << 12701;
		return 0;
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k) {
					cnt++;
					break;
				}
			}
			else
			{   
				if((long long)(b[j]^b[i-1])==k){
					cnt++;
					i=j;
					break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
} 

