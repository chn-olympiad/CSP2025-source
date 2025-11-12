#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin >> a;
    int j = 0;
    int nums[10] = {0,0,0,0,0,0,0,0,0,0};
    while(j < a.size()){
        if(a[j] == "0")nums[0]++;
        else if(a[j] == "1")nums[1]++;
        else if(a[j] == "2")nums[2]++;
        else if(a[j] == "3")nums[3]++;
        else if(a[j] == "4")nums[4]++;
        else if(a[j] == "5")nums[5]++;
        else if(a[j] == "6")nums[6]++;
        else if(a[j] == "7")nums[7]++;
        else if(a[j] == "8")nums[8]++;
        else if(a[j] == "9")nums[9]++;
        j ++;
    }
    for(int i = 9;!i <0;i--){
        for(NULL;nums[i] > 0;nums[i] --){
            cout<<i;
        }
    }
    return 0;
}
//~string 忘了。。。。。
