#include<bits/stdc++.h>
using namespace std;
char c[1000011];
int a[1000011];
int len=0,cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",&c);
    //cout<<c<<endl;
    for(int i=0;c[i]!=0;i++){
        if(isdigit(c[i])){
            a[++cnt]=c[i]-'0';
        }
        len++;
    }
    //cout<<len<<endl;
    sort(a+1,a+1+cnt);
    for(int i=cnt;i>=1;i--){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
