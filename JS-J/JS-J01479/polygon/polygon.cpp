#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    vector <int> a;
    for(int i=0;i<n;i++){
        int sb;
        cin>>sb;
        a.push_back(sb);
    }
    if(*max_element(a.begin(),a.begin()+3)*2<a[0]+a[1]+a[2]) cout<<1;
    else cout<<0;



    return 0;
}
