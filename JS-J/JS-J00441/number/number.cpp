#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b[1000005],j=1;
    memset(b,0,sizeof(b));
    string a;
    cin>>a;
    int c=a.size();
    for(int i=0;i<c;i++)
        if(a[i]>='0'&&a[i]<='9'){
            b[j++]=a[i]-'0';
        }
    sort(b,b+j);
    if(b[j-1]==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=j-1;i>0;i--)
        cout<<b[i];
    cout<<endl;
    return 0;
}
