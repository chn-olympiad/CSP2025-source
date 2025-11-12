#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+2;
int l,ans=INT_MIN,cnt=0;
int nums[12];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            nums[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(nums[i]){
            cout<<i;
            nums[i]--;
        }
    }
    return 0;
}
