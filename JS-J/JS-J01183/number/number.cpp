#include<bits/stdc++.h>
using namespace std;
string num;
int n[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> num;
    for(int i = 0;i < num.size();i++)
        if(num[i] >= '0' && num[i] <= '9') n[num[i] - '0'] ++;
    for(int i = 9;i >= 0;i--){
        if(n[i] != 0){
            while(1){
                if(n[i] == 0) break;
                cout << i;
                n[i]--;
            }
        }
    }
    cout << endl;
    return 0;
}