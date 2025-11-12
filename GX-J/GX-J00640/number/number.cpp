#include<bits/stdc++.h>
using namespace std;
bool h=true;
int m,mi;
string b;
vector<int> a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    for(int i=0;i<b.size();i++){
        a.push_back(b[i]);
    }
    while(h==true){
        m=-1;
        h=false;
        for(int i=0;i<a.size();i++){
            if(a[i]>='0' and a[i]<='9'){
                if(a[i]-'0'>m){
                    h=true;
                    m=a[i]-'0';
                    mi=i;
                }
            }
        }
        if(h==true){
            cout<<m;
            a.erase(a.begin()+mi);
        }
    }
    return 0;
}
