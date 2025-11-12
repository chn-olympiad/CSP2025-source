#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
string s;
int nums[maxn],ind;
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')nums[ind++]=(s[i]-48);
    }
    sort(nums,nums+ind,cmp);
    for(int i=0;i<ind;i++)cout<<nums[i];
    return 0;
}
