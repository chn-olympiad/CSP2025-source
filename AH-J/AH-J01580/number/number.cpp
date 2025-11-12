#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

void run()
{
    string s,tp;
    cin>>s;
    for(auto&i:s)if(isdigit(i))tp+=i;
    sort(tp.begin(),tp.end(),[](char a,char b){return a>b;});
    cout<<tp;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t=1;
    while(t--)
    {
        run();
        cout<<"\n";
    }

    return 0;
}
