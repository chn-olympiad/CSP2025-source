#include<bits/stdc++.h>
using namespace std;
string c;
int n,a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>c;
    for(int i=0;i<c.size();i++){
        if(c[i]>='0'&&c[i]<='9') a[++n]=c[i]-'0';
    }
    sort(a+1,a+n+1);
    if(a[n]==0){
        cout<<0;
        return 0;
    }
    for(int i=n;i>=1;i--) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
