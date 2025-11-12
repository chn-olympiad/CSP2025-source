#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("number.in","r" ,stdin);
    freopen("number.out","w" ,stdout);
    string s;
    int nums[1000009] = {0};
    int numsend = 0;
    cin>>s;
    for(int i = 0; i < s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            nums[numsend] = s[i]-48;
            numsend++;
        }
    }
    sort(nums,nums+numsend,cmp);
    for(int i = 0; i < numsend; i++){
        cout<<nums[i];
    }

    return 0;
}
