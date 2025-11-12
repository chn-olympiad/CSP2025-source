#include<bits/stdc++.h>
using namespace std;
char a[100000000];
int b[100000000],y=1;
int main(){
    cin>>a;
    int  s=sizeof(a);
    for(int i=0;i<s;i++){
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
                y++;
          b[y]+=a[i]-'0';

        }
    }
    sort(b+1,b+y+1);
    while(y>1){
        cout<<b[y];
        y--;
    }
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    return 0;
}
