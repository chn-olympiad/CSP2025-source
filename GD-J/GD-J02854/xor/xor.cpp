#include<bits/stdc++.h> 
using namespace std;
const int N = 1e6;
int n,k;
int a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];	
	int i = 2;
	int b = a[1];
	for(int i = 2;i <= n;i++){
		int c = b ^ a[i];
		if(b == k){
			ans++;
			b = a[i];
			cout << 'a' << ' ';
		}
		else if(c == k){
			ans++;
			i++;
			b = a[i];
		}
		else{
			b = b ^ a[i];
			
		}
	}
	cout << ans;
	return 0;
	

}
