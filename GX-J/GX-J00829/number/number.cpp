#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num[1000005];
    int s=0;
    string a;
    cin >> a;
    if(a.size()==1){
        cout << a;
        return 0;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' and a[i]<='9'){
            num[s]=a[i];
            s++;
        }
    }
    sort(num,num+s,cmp);
    for(int i=0;i<s;i++){
        cout << char(num[i]);
    }
    return 0;
}
