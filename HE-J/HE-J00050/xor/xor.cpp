#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int a[N],sum,num,l=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1) num++;
		if(a[i]==k){
			sum++;
		}else{
			if(a[i]==a[i-1]&&i-1!=l){
				l=i;
				sum++;
			}
		}
	}
	if(k==1){
		cout<<num;
		return 0;
	}
	if(k==0){
		cout<<sum;
		return 0;
	}
	return 0;
}
