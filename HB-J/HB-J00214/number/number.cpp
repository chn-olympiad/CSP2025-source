#include<bits/stdc++.h>
using namespace std;
int b[1000005],n,m;
string a;
bool cmp(int s1,int s2){
    return s1>s2;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            n++;
            b[n]=a[i]-'0';
        }
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(m==0){
            if(b[i]==0){
                cout<<0;
                return 0;
            }
            else{
                cout<<b[i];
                m++;
            }
        }
        else{
            cout<<b[i];
            m++;
        }
    }
    return 0;
}
