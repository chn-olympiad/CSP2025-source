#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1005],l2;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int l=strlen(a);
    for(int i=0;i<l;i++){
        if(a[i]>='0'&&a[i]<='9'){
            l2++;
            b[l2]=int(a[i])-48;
        }
    }
    sort(b+1,b+l2+1);
    for(int i=l2;i>=1;i--) cout<<b[i];
    return 0;
}
