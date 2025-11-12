#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s,sum=0;
    cin>>n>>m;
    vector<int> v;
    cin>>s;
    for(int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        if(v[i]<s){
            break;
        }else{
            sum++;
        }
    }
    sum++;
    if(sum%m==0){
        cout<<sum/m<<" ";
        if((sum/m)%2==0){
            cout<<1;
        }else{
            cout<<m;
        }
    }
    else{
        cout<<sum/m+1<<" ";
        if((sum/m+1)%2==1){
            cout<<sum%m;
        }else{
            cout<<m+1-(sum%m);
        }
    }
}