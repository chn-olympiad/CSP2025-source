#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1e5+3999;
int b1[N],b2[N];

string a1[N],a2[N];
string t1,t2;


int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a1[i]>>a2[i];
        int len1=a1[i].length();
        for(int j=0;j<len1;j++){
            if(a1[i][j]=='b')b1[i]++;
            if(a2[i][j]=='b')b2[i]++;
        }
        //cout<<"afwfw";
    }
    if(b1[0]=0)
    while(q--){
        cin>>t1>>t2;
        int ans=0;
        int len1=t1.length(),len2=t2.length();
        for(int i=0;i<n;i++){
            if(a1[i].length()==len1){
                if(a1[i]==t1&&a1[i]==t2){ans=2;}
                else{
                    int t=0;
                    int r1,r2;
                    while(t++<len1){
                        if(t1[t]=='b')r1=t;
                        if(t2[t]=='b')r2=t;
                    }
                    if(b1[i]==r2&&b2[i]==r1)ans=1;
                }
            }
        }


        cout<<ans<<"\n";
    }

    else{
        while(q--){
                int ans=0;
            cin>>t1>>t2;
            for(int i=0;i<n;i++){
                if(t1.length()!=a1[i].length()){
                    ans+=0;
                }
                else if(t1==a1[i])ans+=2;
        else if(t1==a2[i])ans+=1;

            }
            cout<<ans<<'\n';
        }

    }









    return 0;
}
