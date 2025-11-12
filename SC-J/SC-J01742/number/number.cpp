#include<bits/stdc++.h>
using namespace std;
int a1[1100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;int s=0;
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s++;
			a1[s]=int(a[i]-'0');
			
		}
	}
	sort(a1+1,a1+s+1);
	for(int i=s;i>=1;i--){
		if(a1[s]==0){
			cout<<0;
			return 0;
		}
		cout<<a1[i];
	}
	return 0;
} 