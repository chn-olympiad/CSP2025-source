#include <bits/stdc++.h>
using namespace std;

string s;
int num[1000005],cnt = 0;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= '0'&&s[i] <= '9'){
            num[cnt] = s[i] - '0';
            cnt++;
        }
    }
    sort(num,num+cnt,cmp);
    for(int j = 0;j < cnt;j++){
        cout << num[j];
    }
    return 0;
}
