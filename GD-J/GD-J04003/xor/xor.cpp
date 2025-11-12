#include <bits/stdc++.h>
using namespace std;
const int N = 5*1e5;
int n,k,sum;
int q[N];
bool flag = 1,flag1 = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>q[i];
		if(q[i]!=1){
			flag = 0;
		}
		if(q[i]!=1 and q[i]!=0){
			flag1 = 0;
		}
	}
	if(flag==1 and k==1){
		cout<<n;
		return 0;
	}
	else if(flag==1 and k==0){
		cout<<n/2;
		return 0;
	}
	else if(flag==1 and k>1){
		cout<<0;
		return 0;
	}
	else if(flag1 == 1 and k>1){
		cout<<0;
		return 0;
	}
	else if(flag1 == 1 and k==1){
		for(int i = 0;i<n;i++){
			if(q[i] == 1){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
