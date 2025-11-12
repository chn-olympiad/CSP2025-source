#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
bool fl=true;
string s1[200005],s2[200005],t1[200005],t2[200005],str;
void findd(string st1,string st2,string st3,string st4){
    for(int j=1;j<=st1.size();j++){
        for(int k=1;k<=st1.size();k++){
            for(int m=j;m<=k;m++){
                str[m]=st1[m];
            }
            if(str!=st2){
                fl=false;
                break;
            }
        }
        if(fl==true){
            if(st3==st4){
                ans++;
                return;
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int HAAVK=1;HAAVK<=q;HAAVK++){
        cin>>t1[HAAVK]>>t2[HAAVK];
        for(int i=1;i<=n;i++){
            findd(t1[HAAVK],s1[i],s2[i],t2[HAAVK]);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
