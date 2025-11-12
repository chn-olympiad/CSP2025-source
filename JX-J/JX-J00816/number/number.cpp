#include<bits/stdc++.h>
using namespace std;
int cnt;
char a[1000010],b[1000010];
bool cmp(char x,char y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int alen=strlen(a);
    for(int i=0;i<alen;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[cnt]=a[i];
            cnt++;
        }
    }
    sort(b,b+cnt,cmp);
    for(int i=0;i<cnt;i++) cout<<b[i];
    return 0;
}
