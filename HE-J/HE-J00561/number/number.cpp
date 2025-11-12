#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n,a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<1e6;i++){
        a[i]=-1;
    }
    for(int i=0;i<n;i++){
       if(s[i]>='0' && s[i]<='9'){
         a[i]=s[i]-48;
       }
    }
    sort(a,a+n,cmp);
    for(int i;i<1e6;i++){
        if(a[i]==-1){
            continue;
        }
        else{
            cout<<a[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

