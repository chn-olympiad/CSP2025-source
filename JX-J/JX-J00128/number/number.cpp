#include<bits/stdc++.h>
using namespace std;
int a[1000005],ak=1;
bool cmp(int x,int y){
    return x>y;
}
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[ak]=int(s[i]-48);
            ak++;
        }
    }
    sort(a+1,a+ak+1,cmp);
    for(int i=1;i<ak;i++){
        cout<<a[i];
    }
    return 0;
}
