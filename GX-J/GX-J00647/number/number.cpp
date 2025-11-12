#include<bits/stdc++.h>
using namespace std;
string a;
int nums[1000020],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a;
    int len = a.size();
    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9') nums[++cnt] = a[i]-'0';
    }
    sort(nums+1,nums+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<nums[i];
    }
    return 0;
}
