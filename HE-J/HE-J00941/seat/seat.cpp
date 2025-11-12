#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int lmax=114; // 114514
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin>>n>>m;
	int a[lmax];
	int l=n*m;
	for (int i=1;i<=l;i++){
		cin>>a[i];
	}
	int sc=a[1];
	sort(a+1,a+l+1);
	//find a[1]
	int ai=l;
	for (int i=l;i>=1;i--){
		if (a[i]==sc) break;
		ai--;
	}
	int pos=l-ai;
	int rn=1,rm=1;
	int mbuff=pos/(2*n);
	int mod=pos%(2*n);
	rm=1+mbuff*2;
	if (mod>=n){
		rm++;
		rn=2*n-mod;
	} else {
		rn=mod+1;
	}
	cout<<rm<<" "<<rn;
	return 0;
}
