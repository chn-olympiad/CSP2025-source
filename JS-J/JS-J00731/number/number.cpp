#include<bits/stdc++.h>
using namespace std;
int a[11];
string m;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>m;
    int l=m.length();
    for(int i=0;i < l;i++){
        if(m[i]>='0'&&m[i]<='9'){
            a[m[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
            while(a[i]--){
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
