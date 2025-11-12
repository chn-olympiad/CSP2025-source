#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),a=0;
	char num[n];
	for(int i=0;i<n;i++){
		if(s[i]>='1'&&s[i]<='9'){
			num[a]=s[i];
			a+=1;
		} 
	}
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
			if(num[i]<num[j]){
				int x=num[i];
				num[i]=num[j];
				num[j]=x;
			}
		}
	}
	for(int i=0;i<a;i++){
		cout<<num[i];
	}
	return 0;
} 
