#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    while(b--){
            int yousq=0;
        queue<string>q;
        for(int i=0;i<b;i++){
            string l;
            cin>>l;
            q.push(l);
        }
        char j[a];
        for(int i=0;i<a*2;i++){
            cin>>j[i];
        }
        for(int i=0;i<a*2;i++){

            if(i%2==0){
                char jjj=q.frount();
                if(jjj+j[i]>=jjj)yousq++;
            }else{
                char jjj=q.first;
                if(jjj+j[i]>=jjj)yousq++;
            }
        }
        if(yousq>=b)cout<<yousq;
        for(int i=0;i<b;i++)q.pop();
        for(int i=0;i<a*2;i++)j[i]=0;

    }
   return 0;
}
