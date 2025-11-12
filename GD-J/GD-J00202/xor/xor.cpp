#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool all_1 = 1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] != 1)all_1 = 0;
	}
	int cnt = 0;
	//a
	if(all_1 == 1){
		if(k == 0){
			for(int i = n-1; i >= 1; i -= 2){
				cnt += i;				
			}
		}
	}
	//b
	else{
		if(k == 0){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= i; j++){
					int l = 0;
					for(int p = j; p <= i; p++){
						if(a[p] == 1)l++;
					}
					if(l % 2 == 0){
						cnt++;
					}
				}
			}
		}
		else if(k == 1){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= i; j++){
					int l = 0;
					for(int p = j; p <= i; p++){
						if(a[p] == 1)l++;
					}
					if(l % 2 == 1){
						cnt++;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
