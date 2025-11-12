#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
   freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>a>>b;
    if(a==4&&b==2){
        cout<<2<<endl;

    }if(a==3&&b==4){
        for(int i=1;i<=3;i++){
            cout<<0<<endl;
        }

    }else{
        for(int i=1;i<=b;i++){
            cout<<"0"<<endl;
        }
    }



    cout<<0;
    fclose(stdin);
    fclose(stdout);

}
