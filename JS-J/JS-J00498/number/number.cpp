#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void si(int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<N;i++){
        a[i]=-1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>'9'||s[i]<'0'){
            s[i]=0;
        }
    }
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    si(j);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
