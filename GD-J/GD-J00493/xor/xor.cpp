#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m,a[N];
bool chaker(int q,int z){
	int ans = 0;
	for(int i = q;i <= z;i++){
		ans += a[i];
	}
	if(ans == m) return true;
	else return false;
}
int xo(int q ,int z){
	int d = a[q];
	for(int i = q + 1; i <= z;i++){
		d ^= a[i];
	}
	return d;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	 scanf("%d%d",&n,&m);
	 for(int i = 1;i <= n;i++){
	 	scanf("%d",&a[i]);
	 }
	 int qi = 0,zo = 0,maxa = -2e9;
	 for(int i = 1;i <= n;i++){
	 	for(int j = 1;j <= n;j++){
	 		if(chaker(i,j) && i > qi && j > zo){
	 			qi = i;
	 			zo = j;
	 			maxa = max(xo(i,j),maxa);
			}
		 }
	 }
	 printf("%d",maxa);
	return 0;
}
