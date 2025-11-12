#include<bits/stdc++.h>
using namespace std;
char s1[1000010];
string s;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size(),t=1;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            s1[t]=s[i];
            t++;
        }
    }
    t--;
    sort(s1+1,s1+t+1,cmp);
    for(int i=1;i<=t;i++){
        printf("%c",s1[i]);
    }
    return 0;
}
