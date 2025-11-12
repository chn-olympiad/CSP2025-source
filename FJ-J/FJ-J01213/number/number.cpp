#include<bits/stdc++.h>
using namespace std;
bool b(int m,int n){
	return m>n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000002]={0};
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[ans]=s[i];ans++;
		}
	}
	sort(a,a+ans,b);
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	return 0;
}
