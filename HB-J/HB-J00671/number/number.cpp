#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int p=1;
int cd;
cd=s.length();
for(int i=0;i<cd;i++){
	if(s[i]>='0' && s[i]<='9'){
	a[p]=s[i]-'0';
	p++;
}
sort(a+1,a+p,cmp);
for(int j=1;j<p;j++){
cout<<a[j];
}
}
return 0;
}
