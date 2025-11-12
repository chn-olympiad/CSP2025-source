//T3
#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e5+7;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	if(n == 1||n == 2){
		cout<<n-1;
		return 0;
	}
	if(k == 0){
		bool f = 0;//0 ШЋ1,1 га0га1 
		for(int i = 1;i <= n;i++){
			if(!a[i]){
				f = 1;
				break;
			}
		}
		if(f == 0) cout<<n / 2;
		else{
			int sum = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 0) sum++;
			}
			for(int i = 2;i <= n;i+=2){
				if(a[i]&&a[i-1]) sum++;
			}
			cout<<sum;
		}
		return 0;
	}
	if(k == 1){
		int sum = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) sum++;
		}
		cout<<sum;
		return 0;
	}
	cout<<n / 2;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
