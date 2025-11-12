#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e6+1;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    int sum=0;
    if(n==1){
        cout<<s;
        return 0;
    }
    int ans[N];
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[i]=s[i]-'0';
            if(ans[i]==0){
                ans[i]++;
            }
            sum++;
        }
    }
    sort(ans,ans+sum,cmp);
    for(int i=0;i<sum;i++) cout<<ans[i];
    return 0;
}
