#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[1005],ans=1;
    for(int i=0;i<a.size();i++)
        if(isdigit(a[i])){
            b[ans]=a[i]-'0';
            ans++;
        }
    sort(b+1,b+ans,cmp);
    for(int i=1;i<ans;i++) cout<<b[i];
}
