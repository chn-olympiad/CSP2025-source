#include<iostream>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s1[i]>>s2[i];
    while(q--){
        int cnt=0;
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            int pos=0;
            while(true){
                if(t1.find(s1[i],pos)>1e9)
                    break;
                int x=t1.find(s1[i],pos);
                string tot=t1.substr(0,x)+s2[i]+t1.substr(x+s2[i].length(),t1.length()-x-s2[i].length());
//                cout<<tot<<endl;
                if(tot==t2){
                    cnt++;
                    break;
                }
                pos=x+1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
