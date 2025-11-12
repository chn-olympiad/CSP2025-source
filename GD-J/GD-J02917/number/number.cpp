#include<bits/stdc++.h>
using namespace std;
int m=0;
int a[1000005];
char s;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s){
        if(s>='0'&&s<='9'){
            m++;
            a[m]=s-'0';
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
