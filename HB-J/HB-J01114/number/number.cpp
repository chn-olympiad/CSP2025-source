#include<bits/stdc++.h>
using namespace std;
int s;
int n,a[10010],m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(1){
        if(s/10!=0){
            m++;
        }else{
            break;
        }
    }
    cin>>s;
    if(s/10==0){
        cout<<s;
        return 0;
    }
    for(int i=0;i<m;i++){
        if(s%10>=0 and s%10<=9){
            a[i]=s%10;
        }
    }
    for(int i=0;i<m;i++){
        cout<<a[i];
    }
    return 0;
}
