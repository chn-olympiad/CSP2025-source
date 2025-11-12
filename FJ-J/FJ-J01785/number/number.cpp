#include<bits/stdc++.h>
using namespace std;
string a;
long long s[1000001];
long long l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0 && a[i]-'0'<=9){
			s[l]=a[i]-'0';
			l++;
		}
	}
	sort(s,s+l);
	if(s[l-1]==0){
		cout<<0;
	}
	else{
		for(int i=l-1;i>=0;i--){
			cout<<s[i];
		}
	}
	
	return 0;
} 
