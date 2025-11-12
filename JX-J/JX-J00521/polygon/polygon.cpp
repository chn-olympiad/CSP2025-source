#include <bits/stdc++.h>
using namespace std;
long long n,i,a[1010],sum=1,max=-1,j;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    /*use sum to express where "a" is,sum=1 at the beginning*/
    for(i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a[sum]=s[i]-48;
            sum++;
        }
    }
    for(j=1;j<=sum-1;j++){
        for(i=1;i<=sum-1;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
    for(i=1;i<=sum-1;i++){
        cout<<a[i];
    }
    return 0;
}
