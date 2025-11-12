#include<bits/stdc++.h>
using namespace std;
struct pear{
    int l,r;
};
bool sot(pear a,pear b){
    if(a.l == b.l){
        return a.r < b.r;
    }
    return a.l < b.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pear> b;
    for (int i = 0;i < n;i++)
    {
         cin >> a[i];
    }
    for (int l = 0;l < n;l++)
    {
        for (int r = l;r < n;r++)
        {
            int eksor = a[r];
            for (int i = l;i < r;i++)
            {
                eksor^=a[i];
            }
            if(eksor == k){
                b.push_back({l,r});
            }
        }
    }
    sort(b.begin(),b.end(),sot);
    int cnt = 0;
    for (int i = 0,r = -1;i < b.size();i++)
    {
        if(b[i].l > r){
            r = b[i].r;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
