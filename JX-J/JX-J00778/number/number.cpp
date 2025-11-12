#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int p=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<65){
            a[p]=int(s[i])-48;
            p++;
        }
    }
    sort(a,a+p,cmp);
    for(int i=0;i<p;i++){
        cout<<a[i];
    }

}
