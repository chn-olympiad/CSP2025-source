#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k=0;
void fun(){
    int maxn=-1,p;
    for(int i=0;i<k;i++){
        if(a[i]>maxn){
            maxn=a[i];
            p=i;
        }
    }
    a[p]=-1;
    cout<<maxn;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            a[k]=(int)s[i]-48;
            k++;
        }
    }
    for(int i=0;i<k;i++){
        fun();
    }
    return 0;
}
