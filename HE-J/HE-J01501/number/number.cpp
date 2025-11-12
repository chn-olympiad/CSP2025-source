#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j=0;
	string s;
	cin>>s;
	int n=s.size();
	int a[n+10]={0};
	for(i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';	
			j++;
		}
	}
	sort(a,a+j);
	for(i=0;i<j;i++){
		cout<<a[j-i-1];
	}
}
