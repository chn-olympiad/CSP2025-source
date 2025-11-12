#include<bits/stdc++.h>
using namespace std;
string S="";
int W[1010],Idx=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>S;
    int N=S.size();
    for(int i=0;i<N;i++){
        if(S[i]=='0'||S[i]=='1'||S[i]=='2'||S[i]=='3'||S[i]=='4'||S[i]=='5'||S[i]=='6'||S[i]=='7'||S[i]=='8'||S[i]=='9'){
            W[Idx]=S[i]-'0';
            Idx++;
        }
    }
    sort(W,W+Idx);
    for(int i=Idx-1;i>=0;i--){
        cout<<W[i];
    }
    return 0;
}
