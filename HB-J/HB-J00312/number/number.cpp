#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000005],top=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto c:s){
        if(c>='0'&&c<='9') a[top++]=c-'0';
    }
    sort(a,a+top,greater<int>());
    for(int i=0;i<top;i++) cout<<a[i];
}