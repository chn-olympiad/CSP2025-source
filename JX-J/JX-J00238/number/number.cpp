#include<bits/stdc++.h>
using namespace std;



bool cmp(int x,int y){
    return x>y;
}




int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int number[1000001]={};
    int number_i=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            number[number_i]=s[i]-'0';
            number_i++;
        }

    }
    number_i--;

    sort(number+1,number+1+number_i,cmp);


    for(int i=1;i<=number_i;i++){
        cout<<number[i];
    }












    return 0;
}
