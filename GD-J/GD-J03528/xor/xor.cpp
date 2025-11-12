#include<bits/stdc++.h> 
using namespace std;
//deque;
//vetor;
long long n,k;
struct zzh{
	int si=0,id;
	bool a[10];;
}a[600000];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i].id);
		
	}
	
	if((sum/n)%2==1){
		printf("%lld %lld",sum/n+1,m-(sum%n)+1);
	}
	else printf("%lld %lld",sum/n+1,(sum%n)+1);
	return 0;
}
