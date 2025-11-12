#include<bits/stdc++.h>
using namespace std;
int arr[1000005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9')arr[++cnt]=(s[i]-'0');
    }
    sort(arr+1,arr+cnt+1);
    for(int i = cnt;i>=1;i--)printf("%d",arr[i]);
    return 0;
}
