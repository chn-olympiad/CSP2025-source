#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string b="",b1="";
    deque<string> a,b3,a2,b2;

    cin>>n>>q;
   for(int p=1;p<=n;p++){
        cin>>b>>b1;
        a.push_back(b);
        a.push_back(b1);
   }
    while(q--){
        int s=0;
        cin>>b>>b1;
        while(!a.empty()){
            cout<<2;
            int g=0;
            for(;g+a.front().size()<b.size();g++){
                string c="";
                for(int j=g;j<g+b.size();j++){
                    c+=b[j];

                }
                if(c==b1){
                    s++;
                }
            }
            b2.push_back(a.front());
            b3.push_back(a2.front());
            a.pop_front();
            a2.pop_front();

        }
        while(!b2.empty()){
            a.push_back(b2.front());
            a2.push_back(b3.front());
            b2.pop_front();
            b3.pop_front();
        }
        cout<<s<<endl;
    }

    return 0;
}
