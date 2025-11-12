#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    int c=l;
    for(int i=0;i<=l-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-48;
        }
        else c--;
    }
    sort(a,a+l,cmp);
    for(int i=0;i<=c-1;i++){
        cout<<a[i];
    }
    return 0;
}
