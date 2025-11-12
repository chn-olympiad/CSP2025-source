#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int a[917813];
int id;
int main(){
    freopen("number1.in","r",stdin);
    freopen("number.out","w",stdout);
    len=s.size();
    if(len==1){
        int k=s[0].'0';
        cout<<k;
        return 0;
    }
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int k=s[i].'0';
            id++;
            a[id]<=0;
        }
    }
    sort(a+1,a+1+id);
    cout<<k;

    return 0;
}
