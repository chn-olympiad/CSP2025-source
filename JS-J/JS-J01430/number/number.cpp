#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
bool cmp(long long a, long long b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
long long num=0;
string s;
cin>>s;
for(int i=0;i<s.size();i++){
    if(s[i]>='0' and s[i]<='9') a[++num]=(int(s[i])-48);
}
sort(a+1,a+num+1,cmp);
if(a[1]==0){
cout<<0;
fclose(stdin);
fclose(stdout);
return 0;
}
for(int i=1;i<=num;i++) cout<<a[i];
fclose(stdin);
fclose(stdout);
return 0;
}
