#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> arr;
    for(int i=0;i<int(s.size());i++){
        if(s[i]>='0'&&s[i]<='9'){
            arr.push_back(s[i]-'0');
        }
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<int(arr.size());i++){
        cout<<arr[i];
    }
    return 0;
}
