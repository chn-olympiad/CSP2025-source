#include<bits/stdc++.h>
using namespace std;
int n[15];
string m;
int a=0;
 int main()
{
cin>>m;
for(int i=1;i<=m.size();i++){
if(m[i]>='0'&&m[i]<='9')
{n[m[i]-'0']++;
}
}
for(int i=9;i>=0;i++){
while(n[i]<=0)
{n[i]--;
a=a*10+i;
}
}
cout<<a;
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
return 0;
}
