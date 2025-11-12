#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string str;int num[1000010],cnt;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>str;
    for(auto y:str){
        if(isdigit(y)){
            num[++cnt]=y-'0';
        }
    }
    sort(num+1,num+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)cout<<num[i];
    return 0;
}
