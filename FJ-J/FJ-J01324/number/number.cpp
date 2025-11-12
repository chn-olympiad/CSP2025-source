#include<bits/stdc++.h>

using namespace std;
	string s,f;
	int m=0,n=0,c,x;
	char a[1000001];
	bool o(char a,char b){
		return a>b;
	}
	
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	
	f=s;
	s=f+'*';
	
	for(int i=0;s[i]!='*';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i];
			n++;
			
			
		}
	}
	sort(a,a+n,o);
	for(int i=0;i<n+1;i++){
		cout<<a[i];
	}
	return 0;
} 
