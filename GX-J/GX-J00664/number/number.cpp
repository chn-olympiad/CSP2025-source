#include<bits/stdc++.h>
using namespace std;

string a;
int shuz[1000010],ser;

bool cmp(int b1,int b2){
    return b1>=b2;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]-48<10){
            shuz[ser]=a[i]-48;
            a[i]='q';
            ser++;
        }
    }
    sort(shuz,shuz+ser,cmp);
    for(int i=0;i<ser-1;i++){
        cout<<shuz[i];
    }cout<<endl;
    return 0;
}
