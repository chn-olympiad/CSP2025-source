#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n;
    cin>>n;
    int q;
    cin>>q;
    string st[n][2];
    for(int i=0;i<n;i++){
        cin>>st[i][0]>>st[i][1];
    }

    while(q--){
        string s3;
        string s4;
        cin>>s3>>s4;

        int c=0;
        for(int i=0;i<n;i++){
            string s1=s3;
            string s2=s4;
   //         cout<<i<<s1<<"-"<<s2<<"\n";
            int f=s1.find(st[i][0]);
            if(f!=-1){
                s1.erase(f,st[i][0].size());
                s1.insert(f,st[i][1]);
     //           if(i==2){
       //                 cout<<"a";
   //                 cout<<i<<s1<<"-"<<s2<<"\n";
     //           }

                if(s1==s2){
  //                  cout<<i;
                    c++;
                }
            }
        }
        cout<<c<<"\n";
   }
/*        for(int i=0;i<=a.size();i++){
            if(a[i]!=b[i]){
                for(int j=0;j<n;j++){
                    for(int i)
                }
            }
        }

    }*/
   // cout<<s1;
    return 0;
}
