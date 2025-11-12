#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a+1]={};
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	sort(b+1,b+a+1);
	if(a==3){
		if(b[1]+b[2]>b[3]){
			cout<<1;
		}
		else
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=3;i<=a;i++){
		long long x=1,y=1;
		for(int o=a;o>=a-i+1;o--){
			x=x*o;
			y=y*(a-o+1);
		}
		cnt+=(x/y);
	}
	cout<<cnt;
	return 0;
} 
