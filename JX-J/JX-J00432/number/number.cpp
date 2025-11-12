#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005],cnt,siz;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
siz=s.size();
for(int i=0;i<siz;i++){
	if(s[i]>='0' && s[i]<='9'){
		a[cnt]=s[i]-'0';
		cnt++;
	}
}
sort(a,a+cnt);
for(int i=cnt-1;i>=0;i--) cout<<a[i];

	return 0;
}
