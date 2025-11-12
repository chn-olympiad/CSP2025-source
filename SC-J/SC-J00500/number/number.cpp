#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
long long d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[d]=s[i]-'0';
			d++;
		}
	}
	for(long long i=0;i<d-1;i++){
		for(long long j=0;j<d-1;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	if(a[0]==0)cout<<0;
	else{
		for(long long i=0;i<d;i++)cout<<a[i];
	}
	return 0;
} 