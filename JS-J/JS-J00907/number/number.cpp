#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int num=0,num1=0;
    string s,k;
    char c;
    k+='0';
    cin>>s;
    int z=s.size();
    for(int i=0;i<z;i++){
        if(s[i]>='0'&&s[i]<='9'){
            k+=s[i];
            num++;
            num1=num;
            while(k[num1]>k[num1-1]){
                c=k[num1];
                k[num1]=k[num1-1];
                k[num1-1]=c;
                num1--;
                if(num1==0)break;
            }
        }
    }
    z=k.size();
    for(int i=0;i<z-1;i++){
        cout<<k[i];
    }
    return 0;
}
