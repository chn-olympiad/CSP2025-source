#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);

    string s;
    vector<char> arr(s.size());
    getline(cin,s);
    for (int i=0;i<s.size();i++){
        if (s[i]>=48&&s[i]<=57){
            arr.push_back(s[i]);
        }
    }
    sort(arr.begin(),arr.end());
    for (int i=arr.size()-1;i>=0;i--){
        cout<<arr[i];
    }
    
    return 0; 
}
