#include<bits/stdc++.h>
using namespace std;
long long c[1000005];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	long long b=a.size(),d=0;
	for(long long i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9'){
			c[d]=a[i]-'0';
			d++;
		}
	}
	for(long long i=0;i<d;i++){
		for(long long j=0;j<i;j++){
			if(c[i]>c[j]){
				swap(c[i],c[j]);
			}
		}
	}
	if(c[0]==0){
		cout<<0;
	}
	else{
		for(long long i=0;i<d;i++){
			cout<<c[i];
		}
	}
	
	return 0;
} 
