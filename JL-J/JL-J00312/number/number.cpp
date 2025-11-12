#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[1000924],l=0;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if((a[i]>='0') and (a[i]<='9')) {
            b[l]=a[i]-'0';
            l++;
        }
    }

    sort(b,b+l);
    for(int i=l-1;i>=0;i--)cout<<b[i];
}
