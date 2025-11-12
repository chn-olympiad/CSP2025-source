#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    char c[N]={};
    vector<char> ans;
    cin.getline(c,1000000);
    for(int i=0;i<1000000;i++){
        if(c[i]=='0' || c[i]=='1' || c[i]=='2' || c[i]=='3' || c[i]=='4' || c[i]=='5' || c[i]=='6' || c[i]=='7' || c[i]=='8' || c[i]=='9'){
                ans.push_back(c[i]);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }


    return 0;
}
