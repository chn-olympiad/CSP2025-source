#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+10;
int n,k;
int a[N];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i = 1;i <= n;i++){
		cin >>a[i];
	}
	if(k==0){
		bool f=0;
		for(int i = 1;i <= n;i++){
			if(a[i]==0){
				ans++;f=1;
			}
			else if(a[i] == 0 && a[i-1]==0 && f==0){
				ans++;f=1;
			}
			else if(a[i] == 1 && a[i-1] == 1 && f==0){
				ans++;f=1;
			}else{
				f=0;
			}
		}
	}
	else{
		bool f=0;
		for(int i = 1;i <= n;i++){
			if(a[i]==1){
				ans++;f=1;
			}
			else if(a[i] == 1 && a[i-1] == 0 && f==0){
				ans++;f=1;
			}
			else if(a[i] == 0 && a[i-1] == 1 && f==0){
				ans++;f=1;
			}
			else{
				f=0;
			}
		}
	}
	cout <<ans;
	return 0;
}