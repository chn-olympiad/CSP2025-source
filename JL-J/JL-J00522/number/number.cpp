#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int nums[100010],l = 0;
    for (int i = 0;i < a.size();i++){
        if (a[i] >= '0' && a[i] <= '9'){
            l++;
            nums[l] = a[i] - '0';
        }
    }
    sort(nums+1,nums+l,cmp);
    for (int i = 1;i <= l;i++){
        cout << nums[i];
    }
    return 0;
}

