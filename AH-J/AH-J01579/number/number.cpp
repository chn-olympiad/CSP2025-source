#include<bits/stdc++.h>
using namespace std;
short b[1000005];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size(),k=1;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[++k]=s[i]-'0';
		}
	}
	sort(b+1,b+k+1);
	for(int i=k;i>1;i--){
		cout<<b[i];
	}
return 0;
}
