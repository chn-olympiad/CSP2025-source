#include<bits/stdc++.h>
using namespace std;
string a;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ans[i]){
			cout<<i;
			ans[i]--;
		}
	}
	cout<<endl;
} 
