#include<bits/stdc++.h>
using namespace std;
string a,b;
bool  cmp(int a,int b){
	return a>b;
}
int n[1000010],m,len=0;
int main(){
freopen ("number.in","r",stdin);
freopen ("number.out","w",stdout);
cin>>a;
int al=0;
al=a.size();
for (int i=0;i<al;i++){
	if (a[i]>='0'&&a[i]<='9'){
	n[len]=a[i]-'0';
	len++;
}
}sort(n,n+len,cmp);
for (int i=0;i<len;i++){
	cout<<n[i];
}

return 0;
}
