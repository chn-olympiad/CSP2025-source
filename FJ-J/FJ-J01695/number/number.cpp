#include<bits/stdc++.h> 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
long long a[1000005];
long long p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int q=0;q<s.size();q++){
		if(s[q]>='0'&&s[q]<='9'){
			a[p]=s[q]-'0';
			p++;
		}
	}
	sort(a+0,a+p);
	if(a[p-1]==0){
		cout<<0;
	}
	else{
		for(int q=p-1;q>=0;q--){
			cout<<a[q];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
}
