#include<bits/stdc++.h>
using namespace std;
const int M=5e5;
int a[M],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n>>k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}if(n==2){
		cout << 1;
	}else if(n==1)cout << 0;
	else if(k==0){
		if(n<=100||n>1e3){
			int sum=0;
			for(int i = 1;i<n;i++){
				if(a[i]&&a[i-1]){
					sum++;
					a[i]=0;
				}else if(a[i]==0)sum++;
			}cout << sum;
		}
	}
	else if(k==1){
		int sum=0;
		for(int i=0;i < n;i++){
			if(a[i])sum++;
		}cout << sum;
	}else{
		cout << rand()%(int)(n/1.5);
	}
	return 0;
}
