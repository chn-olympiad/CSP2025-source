#include<bits/stdc++.h>
using namespace std;
string a;
char x[1000005]={0};
int m=0;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            m++;
            x[m]=a[i];
        }
    }
    sort(x+1,x+m+1,cmp);
    for(int i=1;i<=m;i++)
        printf("%c",x[i]);
}
