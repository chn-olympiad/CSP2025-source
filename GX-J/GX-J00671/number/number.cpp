#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> a;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9')a.push_back(s[i]-'0');
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size()-1;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    long long ans=0;
    for(int i=0;i<a.size();i++){
        int j=i;
        while(j!=a.size()-1){
            a[i]*=10;
            j++;
        }
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
