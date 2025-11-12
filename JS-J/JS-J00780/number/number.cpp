#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
    return x>y;
}
vector<int> a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<=a.size()-1;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
}
