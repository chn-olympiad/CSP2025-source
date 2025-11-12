#include<bits/stdc++.h>
using namespace std;
string s;
int k=0;
char a[100005],x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=s.size();i++){
        cin>>x;
        if(x>='0' && x<='9') a[++k]=x;
    }
    for(int i=i;i<=k-1;i++){
        for(int j=1;j<=k-i-1;j++){
            if('a[i]'<'a[i+1]') swap(a[i],a[i+1]);
        }
    }
    for(int i=1;i<=k;i++){
       cout<<a[i];
    }
    return 0;
}
