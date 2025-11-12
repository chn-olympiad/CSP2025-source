#include<bits/stdc++.h>
using namespace std;
struct point{
    int number;
};
struct re{
    int w;
    int first;
    int second;
};
bool cmp(re a, re b){
    if(a.w == b.w){
        return a.first < b.first;
    }else{
        return a.w < b.w;
    }
}
point ls[200000];
re ans [200000];
int p = 0;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> ls[i].number;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            long long result = 0;
            for(int a = i ; a <= j ; a++){
                result = (result^(ls[a].number));
            }
            if(result == k){
                ans[p].w = j-i+1;
                ans[p].first = i;
                ans[p].second = j;
                p++;
            }
        }
    }
    sort(ans, ans+p, cmp);
    int temp = p;
    p = 0;
    int minn = -1, maxx = -1;
    long long ansn = 0;
    while(p < temp){
        if(minn != -1 && maxx != -1 &&(minn > ans[p].first && minn > ans[p].second ||  maxx < ans[p].first && maxx < ans[p].second) || (minn == -1 && maxx == -1)){
            ansn++;
            if(minn != -1 && maxx != -1){
                minn = min(ans[p].first , minn);
                maxx = max(ans[p].second, maxx);
            }else{
                minn = ans[p].first;
                maxx = ans[p].second;
            }
        }
        p++;
    }
    cout << ansn;
    return 0;
}
