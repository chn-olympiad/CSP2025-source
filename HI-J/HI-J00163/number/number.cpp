#include<bits/stdc++.h>
using namespace std;

int a[1000000];

bool c(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';	
		}
	}
	sort(a,a+cnt,c);
	
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
