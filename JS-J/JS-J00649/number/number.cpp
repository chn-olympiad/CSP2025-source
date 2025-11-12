#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000010];
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int n=(int)(s[i]-'0');
            a[n]++;
        }
    }
    long long r=0;
    for(int i=9;i>=0;i--){
        int m=a[i];
        while(m>0){
            r++;
            ans[r]=i;
            m--;
        }
    }
    for(int i=1;i<=r;i++){
        cout<<ans[i];
    }
    return 0;
}
