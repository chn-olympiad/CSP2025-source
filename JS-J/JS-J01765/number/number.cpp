#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //scanf("%s",&s);
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++) printf("%d",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
