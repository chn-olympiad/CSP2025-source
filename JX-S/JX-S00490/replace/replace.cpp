/*#include<bits/stdc++.h>
using namespace std;
string s,ss,w,ww;
map<int,string> m,mi;
int main(){
     //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
   int n,q;
   cin>>n>>q;
  for(int i=1;i<=q;i++){
    cin>>s>>ss;
    m[i]=s;
    mi[i]=s;
  }
  for(int i=1;i<=n;i++){
        for(int j=1;j<=q;j++){
            int ans=0;
            int cnt=0;
            cin>>w>>ww;
            if(s==w&&ss==ww){
                ans++;
            }
            int f=1;
            for(int k=0;k<=m[j].length();k++){
               if(s[k]!=ss[k]){
                   if(w[cnt]!=s[i]||ww[cnt]!=ss[i]){
                        f=0;
                       break;
                   }
                   cnt++;
               }
           }
             if(f==0){ans++;}
             cout<<ans;
        }

    }

}
return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
string s,ss,w,ww;
int main(){
   int n,q;
   cin>>n>>q;
   if(q==1){
      cin>>s>>ss;
      int ans=0;
      for(int i=1;i<=n;i++){
            int cnt=0;
        cin>>w>>ww;
        if(s==w&&ss==ww){
            ans++;
        }
        int f=1;
        for(int i=0;i<=s.length();i++){
            if(w[i]!=ww[i]){
                   if(w[cnt]!=s[i]||ww[cnt]!=ss[i]){
                        f=0;
                       break;
                   }
                   cnt++;
            }
        }
         if(f==0){ans++;}
    }
        cout<<ans;
}
return 0;
}
