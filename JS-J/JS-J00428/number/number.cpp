#include<bits/stdc++.h>
using namespace std;
vector <long long> a;
bool cmp(const long long &A ,const long long &B ){

    return A>B;
}
int main(){
    string s;
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(auto o:a){
       printf("%lld",o);
    }
    return 0;
}
