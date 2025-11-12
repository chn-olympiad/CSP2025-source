#include<bits/stdc++.h>
using namespace std;
string n;
int a[100010],k=1;
bool oo(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0'&&n[i]<='9'){
            a[k]=n[i]-'0';
            k++;
        }
    }
    sort(a+1,a+k+1,oo);
    for(int i=1;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
