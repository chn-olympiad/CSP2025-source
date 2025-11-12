#include<bits/stdc++.h>
using namespace std;

int arr[5006];

bool check(vector<int> nums){
    sort(nums.begin(),nums.end(),greater<int>());
    int sum = 0;
    for(int s : nums) sum += s;
    if(sum > nums[0] * 2) return true;
    return false;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin >> n;

    for(int i = 0;i < n;i ++) cin >> arr[i];

    int cnt = 0;
    for(int m = 3;m <= n;m ++){
        for(int i = 0;i + m < n;i ++){
            vector<int> nums(m);
            for(int j = 0;j < m;j ++) nums.push_back(arr[i + j]);
            if(check(nums)) cnt ++;
        }
    }

    cout << cnt % 998244353;
}