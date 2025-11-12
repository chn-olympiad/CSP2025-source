#include<bits/stdc++.h>
using namespace std;
string s;
string m;
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sum1=s.length();
	for(int i=0;i<sum1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[sum]=s[i];
			sum++;
		}
	}
	for(int i=0;i<sum1;i++){
		for(int j=0;j<sum1;j++){
			if(int(m[j])<int(m[j+1])){
				char y=m[j];
				m[j]=m[j+1];
				m[j+1]=y;
			}
		}
	}
	for(int i=0;i<sum;i++){
		cout<<m[i];
	}
} 
