#include<bits/stdc++.h>
using namespace std;

string shu;
int num[19000000],i=0;

bool pai(int a,int b){
return a>b;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>shu;

    for(int f =0;f<shu.size();f++){
        if(isdigit(shu[f])){
            //cout<<"%"<<i<<"*"<<shu[f]<<endl;
            num[i]=shu[f]-'0';
            i++;
        }
    }
    sort(num,num+i,pai);

    for(int f=0;f<i;f++){
        cout<<num[f];
    }
    return 0;
}
