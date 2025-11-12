#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int> c(n),p(n);
    for(auto& x:c) cin>>x;
    iota(p.begin(),p.end(),0);
    long long ans=0;
    do{
        int t1=0,t2=0;
        for(int i=0;i<n;i++){
            if(t2>=c[p[i]]){
                t2++;
                continue;
            }
            if(s[i]=='1') t1++;
            else t2++;
        }
        if(t1>=m) ans++;
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans<<'\n';
    return 0;
}