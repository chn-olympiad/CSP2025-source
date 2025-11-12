#include<bits/stdc++.h>
using namespace std;
int number[1000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<=1000;i++){
        number[i]=-1;
    }
    int n=0;
    for(int i=0;i<=l-1;i++){
        if(s[i]>='0' && s[i]<='9'){
           number[i]=int(s[i]-'0');
           n++;
        }
    }

    for(int i=1;i<=n;i++){
        int maxn=-1;
        for(int j=0;j<=1000;j++){
            if(number[j]>maxn){
                maxn=number[j];
            }
        }
        cout<<maxn;
        for(int j=0;j<=1000;j++){
            if(number[j]==maxn){
                number[j]=-1;
                break;
            }
        }
    }


    return 0;
}
