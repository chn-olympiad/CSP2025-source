#include<bits/stdc++.h>
using namespace std;
struct node{
    string a,b;
}n[114514];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>n[i].a>>n[i].b;
    }
    int num=0;
    for(int i=0;i<y;i++){
        string x1,y1;
        cin>>x1>>y1;
        if(x1.size()!=y1.size()){
            continue;
        }
        else{
            int g=0;
            bool q=false,w=true,z=true;
            for(int i=0;i<x1.size();i++){
                if(x1[i]!=y1[i] and g=0){
                    g=1;
                    int t=0;
                    int t1=0;
                    for(int t=0;t<x;t++){
                        if(!z) break;
                        if(a[t].x[t1]==x1[i]){
                            q=true;
                            for(i;i<x1.size();i++,t1++){
                             if(a[t].x[t1]!=y1[i]){
                              z=false;
                              w=false;
                              break;
                             }
                            }
                        }
                    }

                }
                else if(g==1){
                    cout<<0<<endl;
                    break;
                }

            }
            if(w and q) cout<<t<<endl;
        }

    }
    return 0;
}
