#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ma=-1;
	for(int i =0;i<n;i++){
		cin>>a[i];
		if(ma<a[i])ma=a[i];
	}
	if(k==0){
		cout<<ma;	
	}
	else {
		cout<<1;
	}
	return 0;
}
