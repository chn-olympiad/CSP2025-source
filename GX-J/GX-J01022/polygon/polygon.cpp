#include<bits/stdc++.h>
using namespace std;

int n, a[5005];


int sum, Max, ans, current[5005], current_len;
void delete_num(int num){
    current[current_len] = 0;
    current_len--;
    if(num==Max){
        Max = -2147483647;
        for(int i=1; i<=current_len; i++){
            Max = max(Max, current[i]);
        }
    }
    sum -= num;
}

void add_num(int num){
    current_len++;
    current[current_len] = num;
    Max = max(Max, num);
    sum += num;
}

void reset(){
    memset(current, 0, sizeof(current));
    sum = 0;
    Max = -2147483647;
}

bool panduan(){
    return sum > (Max*2);
}
void recursion(int len, int left){
    for(int i=left; i<=n-len+1; i++){
        add_num(a[left]);
        if(len==1){
            ans += panduan();
            delete_num(a[left]);
        }
        if(len>1) recursion(len-1, left+1);
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int len=3; len<=n; len++){
        recursion(len, 1);
    }
    cout<<ans;
    return 0;
}
