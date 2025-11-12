#include<iostream>
#include<algorithm>
using namespace std;

int num_list[1000005];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            num_list[cnt] = (s[i] - '0');
            cnt ++;
        }
    }
    sort(num_list, num_list + cnt, cmp);
    for(int i = 0;i < cnt;i ++){
        cout << num_list[i];
    }
    return 0;
}
