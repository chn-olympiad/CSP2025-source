#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;int cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=0;
	int i=0;
	while(i<=n){
		i++;
		if(a[i]==k){cnt++;sum=0;continue;}
		else sum=(sum^a[i]);
		if(sum==k){cnt++;sum=0;continue;}
		if(sum>k){sum=0;continue;}
	}
	cout<<cnt<<endl;

 return 0;
}
