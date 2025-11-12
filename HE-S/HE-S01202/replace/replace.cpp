#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[210000],s2[210000];
string t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        int cnt=0;
        for(int j=1;j<=n;j++){
            int p=t1.find(s1[j])+1;

            //cout<<p<<endl;

            if(!(1<=p&&p<=(int)(t1.size()))) continue;
            else{

              /*  string sss1,sss2,sss3;
                sss1 = t1.substr(0,p-1);
                cout<<sss1<<' ';
                sss2 = s2[j];
                cout<<sss2<<' ';

                cout<<p+(int)s1[j].size()-1<<' '<<(int)t1.size()-1;
                sss3 = t1.substr(  p+(int)s1[j].size()-1,  (int)t1.size() );
                cout<<sss3<<' '; */

                string news=(t1.substr(0,p-1)  +  s2[j]  +t1.substr(  p+(int)s1[j].size()-1,  (int)t1.size() ));
              //  cout<<"news="<<news<<endl;
                if(news==t2) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
