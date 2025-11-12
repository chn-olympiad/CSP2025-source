#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5000;
int n;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if((a[1]+a[2])>a[3]&&(a[1]+a[3])>a[2]&&(a[2]+a[3])>a[1])
			puts("1");
		else
			puts("0");
		
	}
	return 0;
}

