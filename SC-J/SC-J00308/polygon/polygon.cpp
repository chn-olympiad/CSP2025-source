#include<bits/stdc++.h>
using namespace std;
int a; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum,maxn=0;
	cin>>n;
	for(int i=1;i<=3;i++){
		cin>>a;
		maxn=max(maxn,a);
		sum+=a;	
	}
	if(sum>maxn*2)
		cout<<1;
	else
		cout<<0;
	return 0;
}