#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;

    vector<int> arr(106);

    for(int i = 1;i <= n * m;i ++) cin >> arr[i];
    int score = arr[1];

    sort(arr.begin(),arr.end(),greater<int>());

    int index;
    for(int i = 1;i <= n * m;i ++){
        if(arr[i] == score){
            index = i + 1;
            break;
        }
    }
    
    int x = (index - 1) / n + 1;
    int y;
    int s = index % n;
    if(s == 0) s = n;

    if(x & 1) y = s;
    else y = n - s + 1;
    
    cout << x << " " << y;
    return 0;
}