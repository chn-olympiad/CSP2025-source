#include<bits/stdc++.h>
#define N 300005
#define mod 998244853
#define int long long
#define base 31
using namespace std;
string s[N][3];
vector<int> vec[N][3];
int bk[N];
int suan(int p,int op,int l,int r){
    if(r<l)return 0;
    int ans=vec[p][op][r]+mod-(vec[p][op][l-1]*bk[r-l+1]%mod);
    ans%=mod;
    return ans;
}
int as1[N],as2[N];
int suan1(int l,int r){
    if(r<l)return 0;
    int ans=as1[r]-(as1[l-1]*bk[r-l+1]%mod)+mod;
    ans%=mod;
    return ans;
}
int suan2(int l,int r){
    if(r<l)return 0;
    int ans=as2[r]-(as2[l-1]*bk[r-l+1]%mod)+mod;
    ans%=mod;
    return ans;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        int l=s[i][1].length();
        vec[i][1].resize(l+2);
        l=s[i][2].length();
        vec[i][2].resize(l+2);
    }
    bk[0]=1;
    for(int i=1;i<N;i++){
        bk[i]=bk[i-1]*base;
        bk[i]%=mod;
    }
    for(int i=1;i<=n;i++){
        int l=s[i][1].length();
        for(int j=1;j<=l;j++){
            vec[i][1][j]=vec[i][1][j-1]*base+s[i][1][j-1]-'a'+1;
            vec[i][1][j]%=mod;
        }
        l=s[i][2].length();
        for(int j=1;j<=l;j++){
            vec[i][2][j]=vec[i][2][j-1]*base+s[i][2][j-1]-'a'+1;
            vec[i][2][j]%=mod;
        }
    }
    for(int i1=1;i1<=q;i1++){
        string s1,s2;
        cin>>s1>>s2;
        int ans1=0,ans2=0;
        int l=-1,r=0;
        for(int j=1;j<=s1.length();j++){
            if(s1[j-1]!=s2[j-1]){
                if(l==-1)l=j;
                r=j;
            }
        }
        //cout<<"lr:"<<l<<" "<<r<<endl;
       for(int i=1;i<=s1.length();i++){
            as1[i]=as1[i-1]*base+s1[i-1]-'a'+1;
            as1[i]%=mod;
       }
       for(int i=1;i<=s1.length();i++){
            as2[i]=as2[i-1]*base+s2[i-1]-'a'+1;
            as2[i]%=mod;
       }
        int ans=0;
        int len=r-l+1;
        for(int i=1;i<=n;i++){
            //cout<<"i:"<<i<<endl;
            if(s[i][1].length()>=len-1)
            for(int j=1;j<=s[i][1].length()-len+1;j++){
                int r1=j+len-1;
                int a1=suan(i,1,j,r1);
                int a2=suan(i,2,j,r1);
                //cout<<i<<" "<<j<<" "<<r1<<endl;
                //cout<<a1<<" "<<a2<<endl;
                //cout<<suan1(l,r)<<" "<<suan2(l,r)<<endl;
                if(a1==suan1(l,r)&&a2==suan2(l,r)){
                    if(j-1<=l-1&&(s[i][1].length()-r1)<=s1.length()-r){
                        //cout<<"ok1:"<<endl;
                        //cout<<suan(i,1,1,j-1)<<" "<<suan(i,1,r1+1,s[i][1].length())<<endl;
                        //cout<<suan(i,2,1,j-1)<<" "<<suan(i,2,r1+1,s[i][1].length())<<endl;
                        //cout<<"l::::"<<l-(j-1)<<" "<<l-1<<" "<<r+1<<" "<<r+(s[i][1].length()-(r1))<<endl;
                        //cout<<suan1(l-(j-1),l-1)<<" "<<suan2(r+1,r+(s[i][1].length()-(r1)))<<endl;
                        if(suan(i,1,1,j-1)==suan1(l-(j-1),l-1)&&suan(i,1,r1+1,s[i][1].length())==suan2(r+1,r+(s[i][1].length()-(r1))))
                        if(suan(i,2,1,j-1)==suan1(l-(j-1),l-1)&&suan(i,2,r1+1,s[i][2].length())==suan2(r+1,r+(s[i][2].length()-(r1)))){
                            //cout<<"ok2:"<<endl;
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4 2
xabcx xadex

*/
