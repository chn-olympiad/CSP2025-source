#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int t[100000];
int main(){
    //0=48 9=57
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int len=a.size()-1,k=1;
    int b[100000];
    for(int i=0;i<=a.size()-1;i++){
        b[i]=a[i]-'0';
    }

    for(int i=0;i<=len;i++){
        if(b[i]<=9&&b[i]>=0){
            t[k]=b[i];
            k++;
        }
    }
    sort(t+1,t+len+3,cmp);
    for(int i=1;i<=k-1;i++){
        cout<<t[i];
    }
    return 0;
}
