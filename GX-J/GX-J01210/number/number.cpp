#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
string a;
long long b[10000010],ans=0,num=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            if(a[i]=='0') {
                b[ans]=0;
                ans++;
            }
            if(a[i]=='1') {
                b[ans]=1;
                ans++;
            }
            if(a[i]=='2') {
                b[ans]=2;
                ans++;
            }
            if(a[i]=='3') {
                b[ans]=3;
                ans++;
            }
            if(a[i]=='4') {
                b[ans]=4;
                ans++;
            }
            if(a[i]=='5') {
                b[ans]=5;
                ans++;
            }
            if(a[i]=='6') {
                b[ans]=6;
                ans++;
            }
            if(a[i]=='7') {
                b[ans]=7;
                ans++;
            }
            if(a[i]=='8') {
                b[ans]=8;
                ans++;
            }
            if(a[i]=='9') {
                b[ans]=9;
                ans++;
            }
        }
    }
    sort(b+1,b+ans+1,cmp);
    for(int i=1;i<=ans;i++){
        num*=10;
        num+=b[i];
    }
    cout<<num;

    return 0;
}