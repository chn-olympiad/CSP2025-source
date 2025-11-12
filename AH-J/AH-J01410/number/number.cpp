#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string s;

vector<int> ans;

void init(){
    ans.push_back(0);
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;

    init();

    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            ans.push_back(s[i]-'0');
        }
    }

    sort(ans.begin()+1,ans.end(),[](int a,int b){
        return a>b;
    });

    for(int i=1;i<ans.size();i++){
        cout<<ans[i];
    }

    cout<<endl;
    return 0;
}