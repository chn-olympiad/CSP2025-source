#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0,a[1000001];
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	for(int k=0;k<=j;k++){
		for(int i=0;i<=j-k;i++){
			if(a[i]<a[i+1]){
				int b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
	}
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 
