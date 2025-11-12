#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,q,ans,l[200005][2],r[200005][2],c[200005];
string s[200005];
map<string,string> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n>100){
        string s1,s2;
        for(int i=1;i<=n;i++){
            cin>>s1>>s2;
            l[i][0]=s1.find('b');
            l[i][1]=s2.find('b');
            r[i][0]=s1.size()-s1.find('b')-1;
            r[i][1]=s2.size()-s2.find('b')-1;
            c[i]=l[i][1]-l[i][0];
            //cout<<l[i][0]<<' '<<r[i][0]<<"  "<<l[i][1]<<' '<<r[i][1]<<"   "<<c[i]<<endl;
        }
        while(q--){
            cin>>s1>>s2;
            int cc,ll[2],rr[2];
            ll[0]=s1.find('b');
            ll[1]=s2.find('b');
            rr[0]=s1.size()-s1.find('b')-1;
            rr[1]=s2.size()-s2.find('b')-1;
            cc=ll[1]-ll[0];
            for(int i=1;i<=n;i++){
                if(c[i]==cc){
                    if(max(l[i][0],l[i][1])<=max(ll[0],ll[1])&&max(r[i][0],r[i][1])<=max(rr[0],rr[1])){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    string s1,s2;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        cin>>mp[s[i]];
    }
    while(q--){
        ans=0;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<0<<endl;
            continue;
        }
        int len=s1.size();
        /*
        int idx1=-1,idx2=-1;
        string x="",y="";
        for(int i=0;i<len;i++){
            if(s1[i]==s2[i]&&x=="") continue;
            else{
                if(idx1==-1){
                    idx1=i;
                }
            }
            y+=s1[i];
            if(s1[i]!=s2[i]){
                x+=y;
                y="";
                idx2=i+1;
            }
        }
        cout<<x<<endl;
        string a,b;
        a=s1.substr(0,idx1);
        b=s2.substr(idx2);
        cout<<a<<' '<<b<<endl;
        int ans=0;
        for(int i=1;i<=n;i++){

        }
        */
        for(int i=1;i<=n;i++){
            int len2=s[i].size();
          //  cout<<' '<<len2<<','<<s1.size()<<endl;
            for(int j=0;s1.size()>=len2&&j<=s1.size()-len2;j++){
                 //   cout<<"***************\n";
                //cout<<j<<' '<<s1.size()-len2<<endl;
               //     cout<<"***************\n";
                string ne=s1.substr(j,len2);
           //     cout<<i<<' '<<j<<' '<<ne<<endl;
                if(ne==s[i]){
                    if(s2.substr(j,len2)==mp[s[i]]&&s1.substr(0,j)==s2.substr(0,j)&&s1.substr(j+len2)==s2.substr(j+len2)){
                   //         cout<<"ok\n";
                        ans++;
                    }
                }
            }
        }
            cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
