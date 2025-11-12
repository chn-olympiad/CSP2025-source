#include<bits/stdc++.h>
using namespace std;
char s[1000100];
char m[1010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i=0,j=0;
    while(s[i]!='\0'){
        if(s[i]<='9' && s[i]>='0'){
            m[j]=s[i];
            j++;
        }
        i++;
    }
    sort(m,m+j,cmp);
    for(int k=0;k<j;k++){
        cout<<m[k];
    }
    return 0;
}
