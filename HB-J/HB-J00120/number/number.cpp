#include<bits/stdc++.h>
using namespace std;
string s;
char a[2000005];
long long a1;
bool cmp(char A,char B){
    return A>B;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[++a1]=s[i];
    sort(a+1,a+1+a1,cmp);
    for(long long i=1;i<=a1;i++)printf("%c",a[i]);
    cout<<'\n';
    return 0;
}
