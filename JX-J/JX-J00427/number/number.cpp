#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
using ll = long long;
il bool isdigit(char c){
    return c>='0' && c<='9';
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int> nums;
    char c = getchar();
    while((c>='a' && c<='z') || (c>='0' && c<='9')){
        if(isdigit(c)) nums.push_back(c-'0');
        c = getchar();
    }
    sort(nums.begin(),nums.end(),greater<int>());
    for(int i : nums) putchar(i+'0');
    fclose(stdin);
    fclose(stdout);
    return 0;
}
