#include <bits/stdc++.h>
using namespace std;
string s;int a[1000005],b,c;
bool cmp(int a,int b){
return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    c=s.size();
    for(int i=0;i<c;i++){
        if(s[i]>='0'&&s[i]<='9'){
                b+=1;
                a[i]+=s[i]-'0';
        }
        else {

            b+=0;
        }
    }
    sort(a,a+c,cmp);
    for(int i=0;i<b;i++){
        cout<<a[i];
    }
return 0;
}
