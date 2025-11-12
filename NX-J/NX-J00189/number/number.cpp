#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1010]={0},cnt=0;
    for(int i=0;i<1000000;i++){
        if(s[i]>'0'&&s[i]<='9'){
            if(s[i]=='1')
                a[i]=1;
            if(s[i]=='2')
                a[i]=2;
            if(s[i]=='3')
                a[i]=3;
            if(s[i]=='4')
                a[i]=4;
            if(s[i]=='5')
                a[i]=5;
            if(s[i]=='6')
                a[i]=6;
            if(s[i]=='7')
                a[i]=7;
            if(s[i]=='8')
                a[i]=8;
            if(s[i]=='9')
                a[i]=9;
        }
        if(s[i]=='0')
            cnt++;
    }
    for(int i=9;i>0;i--){
        for(int j=1010;j>=0;j--){
            if(a[j]==i){
                cout<<a[j];
                a[j]=0;
            }
        }
    }

    for(int i=0;i<cnt;i++){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
