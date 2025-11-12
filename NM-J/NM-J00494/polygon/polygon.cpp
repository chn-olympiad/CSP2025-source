// Failed lms
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0;long long zero = 0;
vector<int> a;
vector<int> calc;
int solve(int length){
    if(n<3){return 0;}
    else if(n=3){
        sort(a.begin(),a.end());
        if(a[0]+a[1]>a[3]){return 1;}
    }
    else{
        int maxn = 0;
        for(auto x:a){if(x>maxn)maxn=x;}
        return maxn;
    }
}
int main(){
    freopen("./polygon.in","r+",stdin);
    freopen("./polygon.out","w+",stdout);
    cin>>n;int tmp;
    for(int i = n;i;i--){cin>>tmp;a.push_back(tmp);}
    cout<<solve(n);
    fclose(stdin);
    fclose(stdout);return 0;
}