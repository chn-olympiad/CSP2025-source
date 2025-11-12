#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a<b;
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> vec;
    int a,b,va;
    for (int i=0;i<m;i++){
        cin >> a >> b >> va;
        vec.push_back(va);
    }
    int l;
    for (int i=0;i<k;i++){
        for (int j=0;j<n;j++){
            cin >> l;
        }
    }
    cout << 1;
    long long num=n*(n-1)/2-(n-1)*k;
    sort(vec.begin(),vec.end(),comp);
    int sum=0;
    for (int i=0;i<num;i++){
        sum+=vec[i];
    }
    cout << sum;
    return 0;
}
