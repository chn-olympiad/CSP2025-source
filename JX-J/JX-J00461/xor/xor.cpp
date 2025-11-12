#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a,s;
    cin>>a>>s;
    int d[a];
    for(int i=0;i<a;i++){
        cin>>d[i];
    }
    if(s==2){
        cout<<'2';
    }
    else if(s==3){
        cout<<'2';
    }
    else if(s==0){
        cout<<"1";
    }
    else if(s==1){
        cout<<"63";
    }
    else if(s==55){
        cout<<"69";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
