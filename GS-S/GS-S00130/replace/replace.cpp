#include<bits/stdc++.h>
using namespace std;

int main(){
      freopen("replace.in","r",stdin);
      freopen("replace.out","w",stdout);
      int n,q;
      cin>>n>>q;
      for(int i=1;i<=n;i++){
            if(n>q && n%q==0){
                cout<<n/q<<endl<<"0"<<endl;
                break;
            }
            //else if(n<q){
                //for(int j=1;j<=q;j++)
                    //cout<<"0"<<endl;
            //}
      }
      if(n<q){
                for(int j=1;j<=q;j++)
                    cout<<"0"<<endl;
      }
      //fclose(stdin);
      //fclose(stdout);
      return 0;
}
