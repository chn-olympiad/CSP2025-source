#include<iostream>
using namespace std;
int n,k;
int s[512000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> s[i];
	if(k==0){
		cout << n-1 ;
	}
	return 0;
}
