//sum > 2*max
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0;i < n;i++){
            cin >> nums[i];
    }
    sort(nums,nums+n-1);
    int ans = 0;
    for(int i = 0;i < (n - 2);i++){
        for(int j = (i+1);j < (n - 1);j++){
            for(int k = (j+1);k < n;k++){
                if((nums[i]+nums[j])>nums[k]){
                    ans += (1 + (i*(i+1)/2));
                }else if((nums[i]+nums[j])==nums[k]){
                    ans += (i*(i+1)/2);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
