#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string str;
    cin>>str;
    srand(time(0));
    int rand1=rand();
    srand(time(0));
    int rand2=rand();
    srand(time(0));
    int rand3=rand();
    srand(time(0));
    int rand4=rand();
    srand(time(0));
    int rand5=rand();
    srand(time(0));
    int rand6=rand();
    srand(time(0));
    int rand7=rand();
    srand(time(0));
    int rand8=rand();
    cout<<(rand1*rand2)*((rand3*rand4)%998244353)*(rand5*rand6*rand7*rand8%998244353);
    return 0;
}
