#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<int>a;
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]==0||n[i]==1||n[i]==2||n[i]==3||n[i]==4||n[i]==5||n[i]==6||n[i]==7||n[i]==8||n[i]==9){
            a.push_back(n[i]);
        }
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
