
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+3939;
char c;
int ans[N];
long long t=0;
string s;
bool cmp(char x,char y){return x>y;}
int main(){
    freopen("number.out","w",stdout);
    freopen("number.in","r",stdin);
    cin>>s;
    for(int i=0;i<s.length();i++){
            c=s[i];
        if(c>='0'&&c<='9'){
            ans[t++]=c-'0';
        }

    }
    //cout<<"AFWWF";
    sort(ans,ans+t,cmp);
    for(int i=1;i<t;i++){
        printf("%d",ans[i]);
        //cout<<ans[i];
    }

    return 0;
}
