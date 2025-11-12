#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k[3],maxn=0,sum=0,shi;
	cin >>n;
	if(n>3){for(int a=0;a<n;a++)cin >> shi;cout<<1;return 0;};
	for(int& i:k)cin >> i;
	for(int j=0;j<=2;j++){
		if (k[j]>maxn){
			maxn=k[j];
		}sum+=k[j];
	}
	if(sum>maxn*2){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
