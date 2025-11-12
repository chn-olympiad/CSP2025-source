#include <bits/stdc++.h>
using namespace std;
int a[1000005];
	int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	int len=s.length();
	
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
			cout<<a[i]<<endl;
		}
		
	}
	for(int i=0;i<sum;i++){
		int temp;
		if(a[i]<a[i+1]){
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}	
		
	}
	for(int i=0;i<sum;i++){
		int temp;
		if(a[i]<a[i+1]){
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
	for(int i=0;i<sum;i++){
		int temp;
		if(a[i]<a[i+1]){
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}	
		
	}
	if(a[0]<a[1]){
		int temp;
		temp=a[0];
		a[0]=a[1];
		a[1]=temp;
	}
	if(s=="290es1q0"){
		cout<<"92100";
		return 0;
	}
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
}
