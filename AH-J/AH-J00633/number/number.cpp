#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000010];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int l=s.size();
int t=0;
for(int i=0;i<l;i++){
	if(s[i]>='0'&&s[i]<='9'){
		t++;
		a[t]=s[i]-'0';
	}
}
sort(a+1,a+1+t);
for(int i=t;i>=1;i--)cout<<a[i];
return 0;
}
