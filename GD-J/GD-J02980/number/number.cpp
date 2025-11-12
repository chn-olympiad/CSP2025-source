#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int num[1000020];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    long long o=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            o++;
            num[o]=s[i]-'0';
        }
    }
    sort(num+1,num+o+1,cmp);
    for(int i=1;i<=o;i++){
        cout<<num[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
