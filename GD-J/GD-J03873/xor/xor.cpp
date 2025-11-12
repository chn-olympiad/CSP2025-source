#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000002],flag,flag2,res=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] > 1)
			flag = 1;
	}
	if(flag == 0){
		if(k == 1){
			for(int i=1;i<=n;i++){
				if(a[i] == 1)
					res += 1;
			}
		}
		if(k == 0){
			for(int i=1;i<=n;i++){
				if(flag2 == 1){
					flag2 = 0;
					continue;
				}
				if(a[i] == 0)
					res += 1;
				if(a[i] == 1 && a[i+1] == 1){
					res += 1;
					flag2 = 1;
				}
			}
		}
		cout<<res;
	}
	return 0;
}
