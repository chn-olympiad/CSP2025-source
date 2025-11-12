#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b,d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);  
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b++]=s[i]-48;
			d++;
		}
	}
	for(int i=0;i<d;i++){
		for(int j=i;j<d;j++){ 
			if(a[j]>=a[i]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;   
			}
		}
	}
	for(int i=0;i<d;i++){
		cout<<a[i];
	}
	return 0;
}
