#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char ch[maxn];
int a[maxn],i,j;
bool cmp(int x,int y){
    return (x>y);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ch;
    for(i=0;i<strlen(ch);i++){
        if(ch[i]>='0'&&ch[i]<='9'){
            a[j]=ch[i]-'0';
            j++;
        }
    }
    sort(a,a+j,cmp);
    for(i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
