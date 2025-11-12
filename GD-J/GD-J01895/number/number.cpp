#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long m=s.length();
	long long a[m+5];
	long long l=0;
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
