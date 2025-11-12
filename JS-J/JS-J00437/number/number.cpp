#include<bits/stdc++.h>
using namespace std;
int a[1000006];
string s;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    cin>>s;
    long long k=0;
    for(long long i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')a[++k]=int(s[i])-48;
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)cout<<a[i];

    return 0;
}
