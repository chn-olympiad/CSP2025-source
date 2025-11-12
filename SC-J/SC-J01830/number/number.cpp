#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,greater<int>());
	if(a[1]==0){
		cout<<0;
	}else{
		for(int i=1;i<=k;i++){
			cout<<a[i];
		}
		cout<<"\n"; 
	}
	return 0;
} 