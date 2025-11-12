#include <iostream>
using namespace std;
constexpr int N = 5e5+1;
int n,k,ans;
int a[N],pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		pre[i] = (pre[i-1] ^ a[i]);
	}
		for(int l = 1;l<=n;l++){
			for(int r = l;r<=n;r++){
				int sum = a[l];
				if(l!=r) sum = (pre[l-1]^pre[r]);
				if(sum==k) {
					l = r+1;
					ans++;	
				}
			}
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
