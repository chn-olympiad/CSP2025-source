#include<bits/stdc++.h>
using namespace std;
struct r{
    char s;
    int id;
}l[1000005];
bool cmp(r a,r b){
    if(a.s==b.s)
        return a.id>b.id;
    return a.s>b.s;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a1;
    cin>>a1;
    int f=1;
    int a2=a1.length();
    for(int i=0;i<a2;i++){
        if(a1[i]>='1'&&a1[i]<='9'){
            l[f].s=a1[i];
            l[f].id=f;
            f++;
        }
    }
    for(int i=0;i<a2;i++){
        if(a1[i]=='0'&&l[1].s!=NULL){
            l[f].s=a1[i];
            l[f].id=f;
            f++;
        }
    }
    sort(l+1,l+1+f,cmp);
    for(int i=1;i<=f;i++){
        cout<<l[i].s;
    }
    return 0;
}
