#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0') {
            ans.push_back(0);
        }
        else if(a[i]=='1') ans.push_back(1);
        else if(a[i]=='2') ans.push_back(2);
        else if(a[i]=='3') ans.push_back(3);
        else if(a[i]=='4') ans.push_back(4);
        else if(a[i]=='5'){ans.push_back(5);}
        else if(a[i]=='6') ans.push_back(6);
        else if(a[i]=='7') ans.push_back(7);
        else if(a[i]=='8') ans.push_back(8);
        else if(a[i]=='9') ans.push_back(9);
    }
    sort(ans.begin()+0,ans.begin()+ans.size()+1);
    for(int i=ans.size();i>0;i--){
        cout<<ans[i];
    }
    return 0;
}
