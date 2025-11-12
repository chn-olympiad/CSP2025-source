#include<bits/stdc++.h>
using namespace std;
string s;
int numb[1000005],t,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++)if(s[i]<='9'&&s[i]>='0')numb[++t]=s[i]-'0';
    sort(numb+1,numb+t+1);
    for(int i=t;i>0;i--)cout<<numb[i];
    return 0;
}
/*
https://florr.io
lvl 107
carry me!
florr.io name:Crimson_Sky
//freopen("number.in","r",stdin)
//freopen("number.out","w",stdout);

luogu:862989 Crimson_Sky
*/
