#include<bits/stdc++.h> 
using namespace std;
const int N = 2e5+100;
int sub[N],a[N];//9:12-9:40
bool check[N];
signed main(){
//	freopen("D:/noip/xor/xor5.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sub[i] = sub[i-1]^a[i];
	}
	for(int b = 0;b<=n;b++){
		for(int i = 1;i<=n-b;i++){
			int kkksc03 = sub[i-1]^sub[i+b];
			if(kkksc03 == k){
				bool cans = 1;
				for(int kkks = i;kkks<=i+b;kkks++){
					if(check[kkks]){
						cans=0;
						break;
					}
				}
				if(cans){
					for(int kkks = i;kkks<=i+b;kkks++){
						check[kkks]=1;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
