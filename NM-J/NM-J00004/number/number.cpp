#include<bits/stdc++.h>
using namespace std;

string a,s;
int b[1000001];
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i] <= '9'){
            s.push_back(a[i]);
        }
    }
    for(int i=0;i<s.size();i++){
        b[i]=s[i]-48;
    }
    sort(b,b+s.size());
    reverse(b,b+s.size());
    for(int i=0;i<s.size();i++){
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
