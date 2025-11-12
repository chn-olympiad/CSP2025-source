#include<bits/stdc++.h>
using namespace std;
int a[12];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);//printf("",); scanf("",);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    char tmp;
    while(cin>>tmp){
        if(tmp<='9'&&tmp>='0'){
            a[tmp-'0']++;
        }
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    cout<<"\n";
    return 0;
}
