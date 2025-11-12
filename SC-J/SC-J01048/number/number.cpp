#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],u=0;
bool pd(int x,int y){
	return x>y;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
	if(s[i]>='0' && s[i]<='9'){
		a[++u]=s[i]-'0';
	}
}
sort(a+1,a+u+1,pd);
for(int i=1;i<=u;i++){
	cout<<a[i];
}
return 0;
}