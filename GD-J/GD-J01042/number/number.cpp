#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){		
			++ans;
			a[ans]=s[i]-'0';
	
		}
	}
	sort(a+1,a+1+ans);
	for(int i=ans;i>=1;i--){
		cout<<a[i];
	}
} 
