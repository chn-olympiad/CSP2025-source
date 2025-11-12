#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int ans[214514],t=0;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
		t++;
		ans[t]=a[i]-'0';
	}
	}
	sort(ans+1,ans+t+1);
	for(int i=t;i>=1;i--){
		cout<<ans[i];
	}
}
