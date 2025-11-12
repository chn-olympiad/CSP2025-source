#include<bits/stdc++.h>
using namespace std;
string s[100];
bool emp(char st){
    if(st=='0' || st=='1' || st=='2' || st=='3' || st=='4' || st=='5' || st=='6' || st=='7' || st=='8' || st=='9') return 1;
}
bool cmp(int i, int j){
    return i>=j;
}
vector<int>a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<=100;i++){
        cin>>s[i];
    }
    for(int i=0;i++;i<sizeof(s[i])){
        if(emp(s[0][i])){
            a.push_back(s[0][i] - '0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<=a.size();i++) cout<<a[i];
    cout<<1;
}
