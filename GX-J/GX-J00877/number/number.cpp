#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
string a;
int f[100001]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    int t=1;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            f[t]=a[i]-'0';
            t++;
        }
    }
    sort(f+1,f+1+t,cmp);
    for(int i=1;i<t;i++){
        cout<<f[i];
    }
    return 0;
}
