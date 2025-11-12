#include <bits/stdc++.h>
using namespace std;
string n;
long long nums[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(auto i:n){
        if(i>='0'&&i<='9'){
            ++nums[(i-'0')];
        }
    }
    if(nums[9]==0&&nums[8]==0&&nums[7]==0&&nums[6]==0&&nums[5]==0&&nums[4]==0&&nums[3]==0&&nums[2]==0&&nums[1]==0){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;--i){
        for(int j=0;j<nums[i];++j){
            cout<<i;
        }
    }
    return 0;
}
