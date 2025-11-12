#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int a[1000005],p;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++p]=s[i]-'0';
        }
    }
    sort(a+1,a+1+p,cmp);
    for(int i=1;i<=p;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
