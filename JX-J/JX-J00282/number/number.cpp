#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string a;
int datass;
map<int,long long> memo;
int main(){
    memo[0]=0;memo[1]=0;memo[2]=0;memo[3]=0;memo[4]=0;memo[5]=0;memo[6]=0;memo[7]=0;memo[8]=0;memo[9]=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    for(long long i=0;i<a.length();i++){
        datass=int(a[i]);
        if(datass>=48 && datass<=57){
            memo[a[i]-'0']+=1;
        }
    }
    for(int i=9;i>=0;i--){
        if(memo[i]>0){
            if(i>0)break;
            if(i==0){
                cout<<0;
                return 0;
            }
        }
        if(i==0){cout<<0;return 0;}
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<memo[i];j++)cout<<i;
    }
    return 0;
}
