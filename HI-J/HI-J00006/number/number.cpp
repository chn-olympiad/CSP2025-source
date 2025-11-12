#include<bits/stdc++.h>
using namespace std;
int c[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i];
			t++;
		}
	}
	for(int i=0;i<t;i++){
		c[i]=a[i]-'0';
	}
    sort(c,c+t);
	for(int i=t;i>0;i--){
		cout<<c[i-1];
	}
	return 0;
} 
