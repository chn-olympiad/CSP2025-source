#include<bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
string s;
int a[N],tmp=0;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp++;
            a[tmp]=s[i]-'0';
        }
    }
    sort(a+1,a+tmp+1,cmp);
    for(int i=1;i<=tmp;i++){
        cout<<a[i];
    }
    return 0;
}
/*
0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
*/
