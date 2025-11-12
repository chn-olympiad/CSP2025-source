#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,num[1000],t1;
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[t]=s[i];
            t++;
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            if(num[i]>num[j]){
                t1=num[i];
                num[i]=num[j];
                num[j]=t1;
            }
        }
    }
    for(int g=0;g<t;g++){
        cout<<num[g];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
