#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
bool ok(string s){
    for(int i=(int)'c';i<=(int)'z';i++){
        char ch=(char)i;
        if(s.find(ch)!=-1)return false;
    }
    return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    bool flag2=true;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        /*
        if(!ok(s1[i])||!ok(s2[i])){
            flag2=false;
        }
        */
    }
    while(q--){
        int cnt=0;
        string ss1,ss2;
        cin>>ss1>>ss2;
    //    if(flag2){
            for(int i=1;i<=n;i++){
                string sss1=ss1,sss2=ss2;
                int temp=ss1.find(s1[i]);
                if(temp==-1)continue;
                sss1.erase(temp,s1[i].size());
                sss1.insert(temp,s2[i]);
                if(sss1==ss2){
                    cnt++;
                }
            }
            cout<<cnt<<endl;
            continue;
    //    }
        /*
        for(int i=1;i<=n;i++){
            bool flag=true;
            if(ss1.find(s1[i])!=-1){
                int t=ss1.find(s1[i]);
                for(int j=0;j<=t-1;j++){
                    if(ss1[j]!=ss2[j]){
       //                 cout<<ss1[j]<<" "<<ss2[j]<<" ";
                        flag=false;
       //                 cout<<"A\n";
                        break;
                    }
                }
                for(int j=t;j<=t+s1[i].size()-1;j++){
                    if(s2[i][j-t]!=ss2[j]){
                        flag=false;
 //                       cout<<"B\n";
                        break;
                    }
                }
                for(int j=t+s1[i].size();j<=ss2.size();j++){
                    if(ss1[j]!=ss2[j]){
                        flag=false;
   //                     cout<<"C\n";
                        break;
                    }
                }
     //           cout<<"\n";
                if(flag)cnt++;
            }
        }
        cout<<cnt<<endl;
        */
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
