#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long a,b,x=0;
	string aa;
	cin>>a>>b>>aa;
	int c=aa.length();
	long long y[a];
	for(int i=0;i<c;i++){
		if(aa[i]=='1')x++;
	}
	if(b>x){
		cout<<0;
		return 0;
	}
	for(int i=1;i<x;i++){
		x*=i;
	}
	cout<<x;
	return 0;
}
