#include <iostream>
#include <algorithm>
using namespace std;
char s;
int a[1000005];
int cnt=0;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s){
        if(s>='0'&&s<='9'){
            a[++cnt]=s-'0';
        }
    }
    sort(a+1,a+1+cnt,cmp);
    if(a[1]==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}
