#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    ll b[1000001],cnt=0;
    cin>>a;
    int la=a.size();
    for(int i=0;i<la;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[i]=a[i]-'0';
            cnt++;
        }

    }
    sort(b,b+la,cmp);
    for(int i=0;i<cnt;i++){
        cout<<b[i];
    }

    return 0;
}
