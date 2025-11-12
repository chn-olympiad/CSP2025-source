#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int len1=strlen(a);
    int cnt=1;
    for(int i=0;i<len1;i++){
        if(a[i]=='1' or a[i]=='2' or a[i]=='3' or a[i]=='4' or a[i]=='5' or a[i]=='6' or a[i]=='7' or a[i]=='8' or a[i]=='9' or a[i]=='0')
        {
            b[cnt]=a[i]-'0';
            cnt++;
        }
    }
    sort(b+1,b+cnt,cmp);
    for(int i=1;i<cnt;i++){
        cout<<b[i];
    }
    return 0;
}
