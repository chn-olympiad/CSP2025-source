#include<bits/stdc++.h>
using namespace std;

const int IMA = 5e5 + 10;
int n,k;
int lis[IMA];
int one = 0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>lis[i];
		if(lis[i] == 1){
			one++;
		}
	}
	if(k == 0){
		int tot = 0;
		for(int i=0;i<n;i++){
			if(lis[i] == 1 && lis[i + 1] == 1 && i != n - 1){
				tot++;
				lis[i] = -1;
				lis[i+1] = -1;
			}else if(lis[i] == 0){
				tot++;
			}
		}
		cout<<tot;
	}else{
		cout<<one;
	}
	return 0;
}
