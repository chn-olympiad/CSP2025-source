#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
bool cmp(int x,int y){
    return x>y;
}
int chan(char c){
    if(c=='0') return 0;
    if(c=='1') return 1;
    if(c=='2') return 2;
    if(c=='3') return 3;
    if(c=='4') return 4;
    if(c=='5') return 5;
    if(c=='6') return 6;
    if(c=='7') return 7;
    if(c=='8') return 8;
    if(c=='9') return 9;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[N];
    int n[N],k=0;
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<=len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            n[++k]=chan(a[i]);
        }
    }
    sort(n+1,n+1+k,cmp);
    for(int i=1;i<=k;i++){
        printf("%d",n[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
