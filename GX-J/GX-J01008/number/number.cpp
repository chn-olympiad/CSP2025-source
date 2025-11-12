#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
char s[1000005];
int cnt=0;
char a[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    for(int i=0;i<1000005;i++){
        cin>>s[i];
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i];
            cnt++;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
