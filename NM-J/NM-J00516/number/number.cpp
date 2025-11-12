#include<bits/stdc++.h>
using namespace std;
int n, m, f, y;
char x, sum;
string s, a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            s+=a[i];

        }
    }
    m=s.size();
    for(int i=0;i<m;i++){
        sum=0;
        f=0;
        for(int j=0;j<s.size();j++){
            if(s[j]>sum){
                f=j;
                sum=s[j];
            }
        }
        s[f]='0';
        cout<<sum;
    }
    return 0;
}

