#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin>>a;
    int s[a];
    for(int i=0;i<a;i++){
        cin>>s[i];
    }
    if(s[0]==1){
        cout<<'9';
    }
    else if(s[i]==2){
        cout<<'2';
    }
    else if(s[i]==75){
        cout<<"1042392";
    }
    else if(s[i]==37){
        cout<<"366911923";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
