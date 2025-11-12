#include<bits/stdc++.h>
using namespace std;
int uzawa[10];
string reisa;
void Main(){
    cin>>reisa;
    int n=reisa.size();
    for(int i=0;i<n;i++){
        if(reisa[i]>='0'&&reisa[i]<='9'){
            uzawa[reisa[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(uzawa[i]--){
            cout<<i;
        }
    }
    cout<<'\n';
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    Main();
    return 0;
}