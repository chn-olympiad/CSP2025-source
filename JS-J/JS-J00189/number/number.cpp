#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long a[N];
string s;


bool cmp(long long a,long long b){
    return a>b;
}

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);


    cin>>s;
    long long l=s.length();
    long long xiab=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++xiab]=(int)(s[i]-'0');
        }
    }
    sort(a+1,a+xiab+1,cmp);
    for(long long i=1;i<=xiab;i++){
        cout<<a[i];
    }
    return 0;
}
