#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    if(a>b)return true;
    else return false;
}

int main(){
    freopen("number.in","r",stdin);
    string s1="0123456789";
    string s;
    vector<int> v;
    cin>>s;
    for(int i=0;i<s.size();i++){
        // if(s1.find(s[i]) != NULL))v.push_back(s1.find(s[i]));
        if(count(s1.begin(),s1.end(),s[i])>0)v.push_back(s1.find(s[i])));
        // freopen("number.out","w",stdout);
        // cout<<s1.find(s[i])<<' ';
        // fclose(stdout);
    }    
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        freopen("number.out","w",stdout);
        cout<<v[i];
    }
    fclose(stdin);
    fclose(stdout);
 
    return 0;
}