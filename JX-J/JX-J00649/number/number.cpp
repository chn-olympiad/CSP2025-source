#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a={};
    long long shu[10]={},b;
    cin>>a;
     b=a.length();
    for(long long i=0;i<b;i++){
        if(a[i]>='0' and a[i]<='9'){
            a[i]-='0';
            shu[a[i]]++;
        }
    }
    long long i=9;
    while(1){
        if(i==0 and shu[i]==0){
            break;
        }
        if(shu[i]!=0){
            cout<<i;
            shu[i]--;
        }
        else if(shu[i]==0){
            i--;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
