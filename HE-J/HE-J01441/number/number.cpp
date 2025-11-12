#include<bits/stdc++.h> 
using namespace std;
string s;
int a[10010],ans=0;
int main(){
	freopin("number.in","r",stdin);
	freopin("number.out","w",stdout);
	//cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1);
	for(int i=ans;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
