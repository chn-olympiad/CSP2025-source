/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1048580];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=0;
	} 
	if(k==0&&f==1){
		cout<<1<<endl;
		return 0;
	}
	int cnt=0;
	if(k<=1){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		cout<<n-cnt;
		return 0;
	}
	return 0;
}
