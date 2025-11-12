#include<bits/stdc++.h>
using namespace std;
long long a[1000005],q,max,c;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    long long p=0;
    cin>>s;
    q=s.size();
    for(long long i=0;i<q;i++){

        if('0'<=s[i]&&s[i]<='9'){
            a[p]=s[i]-'0';
            p+=1;
        }

    }

    for(long long i=0;i<p;i++){
        for(long long i=0;i<p;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
    for(long long i=0;i<p;i++){
        cout<<a[i];
    }
    return 0;
}
