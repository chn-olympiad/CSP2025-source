#include <bits/stdc++.h>
using namespace std;

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;int k=-1;
cin>>s;int a[1000005];
int d=s.size();
for(int i=0;i<d;i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[++k]=s[i]-'0';
	}
}
sort(a,a+k+1);
for(int j=k;j>=0;j--){
	cout<<a[j];
}

return 0;
}
