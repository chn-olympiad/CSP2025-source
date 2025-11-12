#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fo(i,v) for(auto i:v)
vector<int> nums;
char c='\1';
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(c!=EOF && c!='\n') {
        c=getchar();
        if(c>='0' && c<='9') nums.push_back(c-48);
        else continue;
    }
    sort(nums.begin(),nums.end(),greater<int>());
    fo(i,nums) printf("%d",i);
}
/* Expected Score: 100 */
