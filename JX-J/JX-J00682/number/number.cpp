#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];

bool isnumber(char s){
    if(s>='0' and s<='9') return true;
    return false;
}

bool cmp(int a,int b){
    if(a>=b) return true;
    return false;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long s_size=s.size(),a_size=0;
    for(int i=0;i<s_size;i++){
        if(isnumber(s[i])){
            a[a_size]=s[i]-'0';
            a_size++;
        }
    }
    sort(a,a+a_size+1,cmp);
    for(int i=0;i<a_size;i++){
        printf("%d",a[i]);
    }
    return 0;
}
