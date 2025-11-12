#include<bits/stdc++.h>
using namespace std;
long long N = 5e5+10;
long long n,k;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(k == 0){
		cout << n;
	}
//	if(k == 1){
//		for(long long i = 1;i<=n;i++){
//			q.push(a[i]);
//		}
//		for(long long i = 1;i<=n;i++){
//			wzm = q.front();
//			if(wzm == 1){
//				
//			}
//			q.pop();
//			stk.push(wzm);
//			
//		}
//	}
	return 0; 
} 
