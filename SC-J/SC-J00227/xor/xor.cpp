#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
bool a[N],flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	else{
		if(k==0){
			int num_db1=0,num_0=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					num_0++;
				}
			}
			for(int i=1;i<=n-1;i++){
				if(a[i]==1&&a[i+1]==1){
					num_db1++;
					a[i]=0;
					a[i+1]=0;
				}
			}
			cout<<num_0+num_db1;
			return 0;
		}
		else{
			int num_1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					num_1++;
				}
			}
			cout<<num_1;
		}
	}
	return 0;
}