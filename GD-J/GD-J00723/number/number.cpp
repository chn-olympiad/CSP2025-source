#include<bits/stdc++.h>
using namespace std;
string a;
int b[10000000],sum;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++sum]=a[i]-'0';
		}
	}
	sort(b,b+sum+1);
	if(sum==0){
		cout<<0;
	}
	else{
		for(int i=sum;i>=1;i--){
		cout<<b[i];
	}
	} 
	return 0;
}
