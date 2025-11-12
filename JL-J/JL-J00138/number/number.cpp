#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int num[N],cnt=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a+1;
    int n=strlen(a+1);
    for(int i=1;i<=n;i++){
        if('0'<=a[i]&&a[i]<='9'){
            num[cnt++]=a[i]-'0';
        }
    }
    cnt--;
    sort(num+1,num+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
        cout<<num[i];
    return 0;
}
