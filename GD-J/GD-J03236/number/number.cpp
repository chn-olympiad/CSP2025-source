#include<bits/stdc++.h>
using namespace std;
int b[1000010],sum=0,o=0;
string a;
int main(){
	freopen("number.in","r",stdin);
	
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' &&a[i]<='9'){
			if(a[i]>='1' &&a[i]<='9')o=1;
			sum++;
			b[a[i]-48]++;
		}
	}
	if(o==0){
	cout<<0;
   return 0;
   }
	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			while(b[i]--)
			cout<<i;
		}
	}
	return 0;
} 
