#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int i,a[1000010],x,y;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        x=s[i]-'0';
        if(x>=0&&x<=9){
            y+=1;
            a[y]=x;
        }
    }
    sort(a+1,a+y+1);
    for(i=y;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
