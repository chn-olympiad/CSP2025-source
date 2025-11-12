#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[100086];
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long len = s.length(),ind = 0;
    for(long long i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[ind++] = int(s[i] - '0');
        }
    }sort(a,a + ind,cmp);
    for(long long i = 0;i < ind;i++){
        cout<<a[i];
    }return 0;
}
