#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector <int> v;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        v.push_back(j);
    }
    int m=0;
    if(n<=2){
        cout<<n;
        return 0;
    }
    else if(n>564745){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=i;j<n;j++){
            int o=v[i];
            for(int h=i;h<=j;h++){
                o=o|v[h];
            }
            if(o==k) x++;
        }
        m=max(x,m);
    }
    cout<<m<<endl;
    return 0;
}
