#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	char m[100];
	int sum=0;
	cin>>n;
	for(int i=0;i<n.length();i++){
		if('0'<=n[i]&&n[i]<='9'){
			m[sum]=n[i];
			sum++;
		}
	}
	for(int i=0;i<sum;i++){
		if(m[i]<m[i+1]){
			char a;
			a=m[i];
			m[i]=m[i+1];
			m[i+1]=a;
		}
		for(int i=0;i<sum;i++){
			if(m[i]<m[i+1]){
				char a;
				a=m[i];
				m[i]=m[i+1];
				m[i+1]=a;
			}
	}
	}
	for(int i=0;i<sum;i++){
		cout<<m[i];
	}
	return 0;
}
	
