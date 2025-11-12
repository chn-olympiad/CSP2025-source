#include<bits/stdc++.h>
using namespace std;
string a;
int asd[1000005];
int i_asd=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]>='0' and a[i]<='9'){
            asd[i_asd]=a[i]-'0';
            i_asd++;
        }
    }
    sort(asd,asd+i_asd,cmp);
    for(int i=0;i<i_asd;i++){
        cout<<asd[i];
    }
    return 0;
}
