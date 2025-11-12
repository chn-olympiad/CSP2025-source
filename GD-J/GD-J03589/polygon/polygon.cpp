#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
int a[5086],f[5087][5087];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
		
	if(n<3){
		printf("0");
		return 0;
	}
	if(n==3){
		if(cnt>2*max(max(a[1],a[2]),a[3]))
			printf("1");
		else
			printf("0");
		return 0;
	}
	return 0;
}
