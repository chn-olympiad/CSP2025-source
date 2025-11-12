#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int flag=0,t;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t=int(s[i])-48;
            a[flag]=t;
            flag++;
        }
    
    }
    sort(a,a+flag,cmp);
    if(a[0]==0){
        cout<<0;
    }
    else{

        for(int i=0;i<flag;i++){
        cout<<a[i];
    }
    }
    


    fclose(stdin);
    fclose(stdout);
    return 0;
}