# include <bits/stdc++.h>
using namespace std;
string s; int a[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0; i<n; i++){
        if(s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
    }
    int bz=0;
    for(int i=9; i>=0; i--){
        if(!bz && i==0){
            cout<<"0";
            break;
        }
        for(int j=1; j<=a[i]; j++) cout<<i;
        if(a[i]>0) bz=1;
    }
    return 0;
}
