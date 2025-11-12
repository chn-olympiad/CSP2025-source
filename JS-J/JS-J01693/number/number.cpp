#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int j=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a+1,a+j,cmp);
    for(int i=1;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
