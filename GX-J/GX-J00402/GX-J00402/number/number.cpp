#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000006],k;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)if(a[i]>='0'&&a[i]<='9')b[++k]=int(a[i]-'0');
    sort(b+1,b+k+1,cmp);
    for(int i=1;i<=k;i++)cout<<b[i];
    return 0;
}
