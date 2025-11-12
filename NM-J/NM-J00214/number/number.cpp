#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int s1[1000010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i=0,m=0;
    while(s[i]!='\0'){
        if (s[i]-'0'<=9){
            s1[i]=s[i]-'0';
            m++;
        }
        i++;
    }
    sort(s1,s1+i,cmp);
    for (int j=0;j<m;j++){
        cout<<s1[j];
    }
    return 0;
}
