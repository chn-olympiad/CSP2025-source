#include <bits/stdc++.h> 
using namespace std;

//思路：前缀和 依据：a^b^b = a 
//不会做去重复部分 
//寄 
int a[500005],q[500005] = {},n,k,cnt = 0;
/*
a 2 1 0 3
q 2 3 3 0
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		q[i] = (q[i-1] ^ a[i]);
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			if((q[i]^q[j]) == k){
//				printf("i:%d j:%d q[i]:%d q[j]:%d q[i]^q[j]:%d k:%d\n",i,j,q[i],q[j],q[i]^q[j],k);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
/*
4 2
2 1 0 3
*/
