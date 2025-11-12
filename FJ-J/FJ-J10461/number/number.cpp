#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100001]={};
	int n=s.length();
	int sum=0;
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[sum]=int(s[i]-'0');
			sum++;
		}
	}
	sort(a,a+sum);
	
	for(int i=sum-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

