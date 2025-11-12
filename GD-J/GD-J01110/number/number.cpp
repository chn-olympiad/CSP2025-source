#include<bits/stdc++.h>
using namespace std;
string s;
int c;
int n,cnt=0,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	int a[n],num[10]={0};
	cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			c=s[i]-'0';
			num[c]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		t=num[i];
		while(t--){
			cout<<i;
		}
	}
	return 0;
}
