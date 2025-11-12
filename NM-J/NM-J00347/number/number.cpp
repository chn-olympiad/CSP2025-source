#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
	cin>>s;
    vector<int> arr;
    for (int i = 0;i<s.size();i++) {
        if (s[i]>='0'&&s[i]<='9')arr.push_back(s[i]-'0');
    }
    sort(arr.begin(),arr.end());
    for (int i = arr.size()-1;i>=0;i--)cout<<arr[i];
    return 0;
}
