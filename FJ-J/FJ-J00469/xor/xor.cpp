#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	unsigned long n,t,a[500005]={0},ans=0,tmp=0;
	cin >> n >> t;
	for(unsigned long i = 0;i < n;i++)cin >> a[i];
	for(unsigned long i = 0;i < n;i++){
		tmp ^= a[i];
		if(tmp == t){
			tmp=0;
			ans++;
		}
	}
	cout << ans;
	fclose(stdout);
	fclose(stdin);
}
