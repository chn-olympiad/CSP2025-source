#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int a[1000010],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    int st=1;
    while(a[st]==0&&st<cnt) st++;
    for(int i=st;i<=cnt;i++) printf("%d",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
