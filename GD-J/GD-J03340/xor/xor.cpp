#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ; 
long long a[N] ; 
long long sum = 0 ; 
struct node{
	int l ;
	int r ;
}x[N];
bool cmp(node q , node p){
	return q.r < p.r ; 
}
int main(){
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ; 
	int n ,  k ; 
	cin >> n >> k ;
	int ans = 0 ;
	for(int i = 1 ;  i <= n ; i++){
		cin >> a[i] ;
	} 
	int cnm = 0 ; 
	int ll = 1 ;
	int awe = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		if(a[i] == k){
			++cnm ; 
			x[cnm].l = i ;
			x[cnm].r = i ; 
		}
		sum = (sum^a[i]) ;
		if(sum == k){
			++cnm ; ;
			x[cnm].l = ll ;
			x[cnm].r =  i ;
			ll = i+1 ; 
			sum = 0 ; 
		} 
	}
	sort(x+1,x+1+cnm,cmp) ; 
	int R = 0 ;
	for(int i = 1 ; i <= cnm ;i++){
		while(i<=n&&x[i].l<=R)i++ ;
		if(i>n)break ; 
		R = x[i].r ;
		awe++ ; 
	}
	cout << awe ;
	return 0 ;
}
