#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int cnt=0;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]+=s[i];
            cnt++;
        }
        else{
            continue;
        }
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
