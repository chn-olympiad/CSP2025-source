#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string zyz;
    getline(cin,zyz);
    for(int i=0;i<=zyz.size();i++){
        if(zyz[i]>='0'&&zyz[i]<='9'){
            a[++cnt]=zyz[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=1;i<=cnt;i++){
        cout<<a[cnt-i+1];
    }
    return 0;
}
