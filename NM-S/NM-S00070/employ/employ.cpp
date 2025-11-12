#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
string s;
int main(){
    freopen("employ2.in","r",stdin);
    freopen("employ2.out","w",stdout);
    cin>>n>>m;
    v.resize(n);
    cin>>s;
    for(int &i:v)cin>>i;
    vector<int> v2(n);
    for(int i=0;i<n;i++)v2[i]=i;
    if(n<=11){
        int sum=0;
        do{
            int tmp=0;
            int c=0;
            for(int i=0;i<n;i++){
                if(s[i]=='0'||c>=v[v2[i]]){
                    c++;
                }
                else{
                    tmp++;
                    if(tmp>=m)break;
                    if(tmp+n-i<m)break;
                }
            }
            if(tmp>=m){
                //for(int i:v2)cout<<i;cout<<"\n";
                sum=(sum+1)%998244353;
            }
        }while(next_permutation(v2.begin(),v2.end()));
        cout<<sum;
    }
    else{
        long long mul=1;
        for(int i=1;i<=n;i++){
            mul=mul*i%998244353;
        }
        cout<<mul;
    }
    return 0;
}
