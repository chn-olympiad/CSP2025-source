#include<bits/stdc++.h>
using namespace std;
string s;
int n,t=0;
int a[100010]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if((s[i]>='1' && s[i]<='9') || s[i]=='0'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t);
	if(a[t-1]==0 && t-1>0){
		cout<<"0";
		return 0;
	}
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
