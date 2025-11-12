#include<bits/stdc++.h>
using namespace std;
long long n,m,nums;
vector<int>s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n>> m;
    for(long long i = 1; i <= n*m; i++){
        int x;
        cin >> x;
        s.push_back(x);
        if(i == 1) nums = s[i];
    }sort(s.begin(),s.end());
    for(int i = n*m; i >= 0; i--){
        if(s[i] == nums) nums = i;
    }
    if(nums <= n){
        cout << 1<< " "<< nums;
    }else{
        if(nums % n == 0){
            if(nums / n % 2 == 0){
                cout << nums / n / 2<< " "<< 1;
            }else{
                cout << nums / n / 2 + 1<< " "<< n;
            }
        }else if(nums / n < 2){
            cout << 2<< " "<< n-(nums%n+1);
        }else{
            if(nums / n % 2 == 0){
                cout << nums / n + 1<< " "<< nums % n ;
            }else{
                cout << nums / n + 1<< " "<< n - (nums % n);
            }
        }
    }
    return 0;
}

