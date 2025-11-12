#include<bits/stdc++.h>
using namespace std;
int a[500001];
int maxnum,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&num==0) num=1;
			if(a[i]==1&&num==1){
				num=0;
				maxnum++;
			}
			if(a[i]==0){
				maxnum++;
				num=0;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1) maxnum++;
		}
	}
	cout<<maxnum;
	return 0;
}
