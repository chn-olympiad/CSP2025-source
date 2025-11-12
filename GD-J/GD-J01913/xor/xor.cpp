#include<bits/stdc++.h>
using namespace std;
bool w[500005];
int a[500005];
int n,k,num1,num2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)num1++;
		else num2++;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i-1]==1&&w[i-1]==0&&w[i]==0){
				w[i]=1,w[i-1]=1;
				num2++;
			}
		}
		cout<<num2;
	} else{
		cout<<num1;
	}
	return 0;
}
