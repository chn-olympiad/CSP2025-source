#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
long long a[N],j=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;s[i];++i){
        if(s[i]>='0'&&s[i]<='9'){
            a[++j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1,cmp);
    for(long long i=1;i<=j;++i){
        printf("%d",a[i]);
    }
    return 0;
}
