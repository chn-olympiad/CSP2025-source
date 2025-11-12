
#include<bits/stdc++.h>
using namespace std;
string a;
int counts[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i = 0;i<a.size();i++){

        if(a[i]>='0' && a[i]<='9') counts[a[i] - '0']++;
    }
    bool isonlyzero = true;
    for(int i = 9;i>=0;i--){
        if(counts[i] != 0){
            cout<<i;
            if(i!=0) isonlyzero = false;
            counts[i]--;
            if(counts[i]!=0 && (i!=0 || !isonlyzero)) i++;
        }
    }
    cout<<endl;
    return 0;
}
