#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n[100000];
	cin>>s; 
	long long j=0,a=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			n[j]=s[i]-48;
			j++;
		}
	}
	
	long long max=n[0],k=0;
	for(int i=0;i<j;i++){
		for(int x=i;x<=j;x++){
			if(n[x]>max){
				max=n[x];
				k=x+i;
			}
		}
		a=n[i];
		n[i]=n[k];
		n[k]=a;
		long long max=-1;
	}for(int i=0;i<j;i++){
		cout<<n[i];
	}
	
	return 0;
	
}
