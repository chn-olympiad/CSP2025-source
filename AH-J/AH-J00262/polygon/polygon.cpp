#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon,in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	int a[5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m=0;
	for(int i=0;i<n;i++){
		m+=a[i];
	}
	int b=a[0],c=a[1];
	int max=a[2];
	if(max<b)
		max=b;
	else{
		if(max<c)
			max=c;}
	if(m>2*max){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
