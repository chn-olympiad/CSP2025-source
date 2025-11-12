#include<bits/stdc++.h>
using namespace std;
char a[26];
int b[10];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
double s;
cin>>s;
for(int i=1;i<=1000010;i++)
{
    if(s[i]!='a'&&s[i]!='b'&&s[i]!='c'&&s[i]!='d'&&s[i]!='e'&&s[i]!='f'&&s[i]!='g'&&s[i]!='h'&&s[i]!='i'&&s[i]!='j'&&s[i]!='k'&&s[i]!='l'&&s[i]!='m'&&s[i]!='n'&&s[i]!='o'&&s[i]!='p'&&s[i]!='q'&&s[i]!='r'&&s[i]!='s'&&s[i]!='t'&&s[i]!='u'&&s[i]!='v'&&s[i]!='w'&&s[i]!='x'&&s[i]!='y'&&s[i]!='z'){
        b[s[i]-'0']++;
    }
    if(s[i]=' ') break;
}
for(int i=1;i<=10;i++){
   for(int j=0;j<=b[i];j++){
    cout<<i;
   }
}
return 0;
}
