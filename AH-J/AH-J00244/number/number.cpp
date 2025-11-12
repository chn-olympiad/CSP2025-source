#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt=0;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=(int)s[i];
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<char(a[i]);
    }


    return 0;
}
