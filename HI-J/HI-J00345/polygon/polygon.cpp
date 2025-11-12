#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long ans;
int a[5005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(a[1]<a[2]+a[3])cout << 1;
	else cout << 0;
	return 0;
} 
