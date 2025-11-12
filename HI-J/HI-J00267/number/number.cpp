#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//string pai xu
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int a[100005]={0},b[100005]={0},c[100005];
	string s;
	getline(cin,s);
	int k=0,l=0;
		for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			l++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-48;
 		k++;
 	
		}
		if(s[i]>='a'&&s[i]<='z'){
			c[i]=1;
		}
	
	}
	
sort(a+0,a+k,cmp);	

for(int i=0;i<k+1;i++){
if(a[i]!=0){
	cout<<a[i];
}
}

for(int i=0;i<l;i++){
cout<<0;
}

	return 0;
}
