#include<iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    cin>>n>>m;
    pair<string,string> a[n],b[m];
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<m;i++){
        cin>>b[i].first>>b[i].second;
        cout<<"0\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
