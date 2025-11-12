#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c;
    unordered_map<string,string> d;
    for(c=0;c<a;c++){
        string e,f;
        cin>>e>>f;
        d[e]=f;
    }
    for(c=0;c<b;c++){
        string e,f;
        cin>>e>>f;
        int g,h,i,k=0;
        for(g=0;g<e.size();g++){
            for(h=g;h<e.size();h++){
                string j="";
                for(i=g;i<=h;i++){
                    j+=e[i];
                }
                if(d[j]!=""){
                    string l=e;
                    for(i=g;i<=h;i++){
                        l[i]=d[j][i-g];
                    }
                    for(i=0;i<e.size();i++){
                        if(l[i]!=f[i]){
                            break;
                        }
                        if(i==e.size()-1){
                            k++;
                        }
                    }
                }
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
