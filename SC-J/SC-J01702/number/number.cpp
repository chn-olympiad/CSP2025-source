#include<bits/stdc++.h>
using namespace std;
int s[1000010];
int main(){
	string a;
	cin>>a;
	int n=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			a[i]-='0';
			s[n]=a[i];
			n++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			int d=s[j],x=s[j+1];
			s[j]=max(x,d);
			s[j+1]=min(x,d);
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<s[i];
	}
} 