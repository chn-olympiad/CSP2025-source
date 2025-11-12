#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
//异或：不同为1，相同为0 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool flag = 1;
    for(int i = 1;i<=n;i++){
    	cin >> a[i];
    	if(a[i]!=1){
    		flag = 0;
		}
	}
	if(flag && k==0){
		cout << n/2;
		return 0;
	}
	if(k==0){
		int num = 0;
		for(int i = 1;i<=n;){
			if(a[i]==0){
				num++;
				i++;
			}else if(a[i]==1 && a[i+1]==1){
				num++;
				i+=2;
			}else{
				i++;
			}
		}
		cout << num;
		return 0;
	}
	if(k==1){
		int num = 0;
		for(int i = 1;i<=n;i++){
			if(a[i]==1){
				num++;
			}
		}
		cout << num ;
		return 0;
	}
	return 0;
} 
