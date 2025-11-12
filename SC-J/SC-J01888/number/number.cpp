#include "bits/stdc++.h"
#define LL long long
#define VT vector
#define lst(type,size) new type[size]
using namespace std;
int n[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char t;
	int l=0;
	while(cin>>t){
		if(t>='0' && t<='9'){
			n[l]=t-'0';
			l++;
		}
	}
	sort(n,n+l);
	for(int i=l-1;i>=0;i--){
		printf("%d",n[i]);
	}
}