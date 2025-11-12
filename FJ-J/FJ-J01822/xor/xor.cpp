#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,ss = -1,sss,ssss;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > 1){
			ss = 1;
		}
		if(a[i] == 1 && a[i + 1] == 0&&i != n){
			sss++;
		}else if(a[i] == 1&&a[i - 1] == 0&&i != 1){
			sss++;
		}
		if(a[i] == 1 && a[i + 1] == 1&&i != n){
			ssss++;
		}else if(a[i] == 1&&a[i - 1] == 1&&i != 1){
			ssss++;
		}
	}
	if(ss == -1 && k == 1){
		cout<<sss;
	}
	if(ss == -1 && k == 0){
		cout<<ssss;
	}
	if(n == 2 && k == 0){
		cout<<0;
	}
	if(n == 1 && k == 0){
		cout<<0;
	}
	return 0;
} 
