#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    long long n=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]=='0'){
            n++;
            a[n]=0;
            continue;
        }
        if(s[i]=='1'){
            n++;
            a[n]=1;
            continue;
        }
        if(s[i]=='2'){
            n++;
            a[n]=2;
            continue;
        }
        if(s[i]=='3'){
            n++;
            a[n]=3;
            continue;
        }
        if(s[i]=='4'){
            n++;
            a[n]=4;
            continue;
        }
        if(s[i]=='5'){
            n++;
            a[n]=5;
            continue;
        }
        if(s[i]=='6'){
            n++;
            a[n]=6;
            continue;
        }
        if(s[i]=='7'){
            n++;
            a[n]=7;
            continue;
        }
        if(s[i]=='8'){
            n++;
            a[n]=8;
            continue;
        }
        if(s[i]=='9'){
            n++;
            a[n]=9;
            continue;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
