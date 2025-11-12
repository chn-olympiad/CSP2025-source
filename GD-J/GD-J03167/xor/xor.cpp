#include<bits/stdc++.h>
using namespace std;
/*  ^  */
int n,k;
bool op[500000];
int a[500000];
int main(){
	int cnt=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			op[i]=1;
			cnt++;
		}
	}
	for(int i=2;i<=n;i++){
		int sum[i+1];
		for(int j=1;j<=n;j++){
			if(op[j]==0){
				sum[j]=a[j];
			}else{
				memset(sum,0,i+1);
			}
		}
		int tmp=sum[1];
		for(int j=2;j<=i;j++){
			tmp=tmp^sum[j];
		}
		if(tmp==k){
			cnt++;
			for(int j=2;j<=i;j++){
				op[j]=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
