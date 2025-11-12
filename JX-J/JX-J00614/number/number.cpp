#include<bits/stdc++.h>
using namespace std;
//void read(){
//    do{
//        char c=getchar();
//    }while(c>'9'||c<'0');
//    do{
//}
//}
int a[1100000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    char c;
    do{
        c=getchar();
        if(c<='9'&&c>='0'){
            cnt++;
            a[cnt]=c-'0';

        }
    }while(c!='\n');
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        printf("%d",a[i]);
    }
    cout<<'\n';
    return 0;
}
