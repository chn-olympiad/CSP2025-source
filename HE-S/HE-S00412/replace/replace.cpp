#include <bits/stdc++.h>
using namespace std;
int n,q,cnt=0,cnt1=0;
string s[20010],t,s1,s2;
bool ok=false;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i+=2){
       for(int j=1;j<=q;j++){
            cin>>s1>>s2;
        for(int k=0; k<s[i].length(); k++)
        {
            int l=s1.length();
            if(s[i].substr(k,k+l-1)==s1)
            {   if(s1.length()==s[i].length()){
                    t=s1;
            }
                else{
                    t=s[i].substr(0,k)+s2+s[j].substr(i+l,s[i].length()-k-l-1);
                }
            }
            if(t==s[i+1])
            {
               cnt++;
               ok=true;
            }
        }
        if(ok==true){
            cout<<cnt<<endl;
        }
        else{
            cout<<0<<endl;
        }
        cnt=0;
        ok=false;
    }


    }

    return 0;
}
