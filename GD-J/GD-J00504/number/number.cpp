#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen('number.in','r',stdin);
	freopen('number.out','w',stdout);
	string s;
	cin>>s;
	int a[sizeof(s)+1];
	for(int i=0;i<sizeof(s)+1;i++){
		a[i]=0;
	}
	int c=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(a[j]<a[j+1]){
				int b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(int i=0;i<c;i++){
		cout<<a[i];
	}
	return 0;
} 
