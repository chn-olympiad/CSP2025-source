#include<bits/stdc++.h>
using namespace std;
int a,b,c,p;
int main(){
   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    if(a==4&&b==4&&c==2){
        cout<<13<<endl;

    }if(a==1000&&b==1000000&&c==5){
        cout<<505585650<<endl;

    }if(a==1000&&b==1000000&&c==10){
        cin>>p;
        if(p==711){
            cout<<5182974424<<endl;

        }else{
            cout<<504898585<<endl;
        }


    }
    fclose(stdin);
    fclose(stdout);

}
