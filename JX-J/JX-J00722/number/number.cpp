#include<bits/stdc++.h>
using namespace std;
vector<char> g;
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     string s;
     cin>>s;
     for(int i=0;i<=s.size()-1;i++){
         if(s[i]>='0'&&s[i]<='9'){
            g.push_back(s[i]);
         }

     }
     sort(g.begin(),g.end());
     for(int i=g.size()-1;i>=0;i--){
         cout<<g[i];
     }
     fclose(stdin);
     fclose(stdout);
     return 0;

}
