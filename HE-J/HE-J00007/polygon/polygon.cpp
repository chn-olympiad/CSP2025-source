#include <iostream>
using namespace std;
long long n,a[10005];
long long cnt=0,maxn=-1,sum=0;
bool flag=1;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int co=0;
		for(int j = i;j <= n;j++){
			co++;
			if(maxn*2<sum && co>=3){
				cnt++;
				continue;
			}
			else{
				sum+=a[i];
				maxn=max(a[i],maxn);
			}
		}
	}
	cout << cnt%998244353;
	return 0;
}
