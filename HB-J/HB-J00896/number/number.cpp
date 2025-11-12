#include<bits/stdc++.h>
using namespace std;
void pd(string d);
vector<int>a;
long long y=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    a.push_back(0);
    string s;
    cin>>s;
    pd(s);
    for(int i=y;i>=1;i--){
        for(int j=1;j<i;j++){
            if(a[j]<=a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=y;i++){
        cout<<a[i];
    }
    return 0;
}
void pd(string d){
    for(int i=0;i<d.length();i++){
        if(d[i]=='1'||d[i]=='2'||d[i]=='3'||d[i]=='4'||d[i]=='5'||d[i]=='6'||d[i]=='7'||d[i]=='8'||d[i]=='9'||d[i]=='0'){
            a.push_back(d[i]-'0');
            y++;
        }
    }
    return;
}
