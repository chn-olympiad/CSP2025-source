#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

struct node{
    int l11,l12,l21,l22;
};

int n,q;
node a[maxn],t[maxn];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                a[i].l11=j;
                a[i].l12=s1.size()-j-1;
            }
        }
        for(int j=0;j<s2.size();j++){
            if(s2[j]=='b'){
                a[i].l21=j;
                a[i].l22=s2.size()-j-1;
            }
        }
    }

    for(int i=1;i<=q;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                t[i].l11=j;
                t[i].l12=s1.size()-j-1;
            }
        }
        for(int j=0;j<s2.size();j++){
            if(s2[j]=='b'){
                t[i].l21=j;
                t[i].l22=s2.size()-j-1;
            }
        }
    }

    for(int j=1;j<=q;j++){
        int ans=0;
        for(int i=1;i<=n;i++){
            bool a1=a[i].l11<=t[j].l11;
            bool a2=a[i].l12<=t[j].l12;
            bool a3=a[i].l21<=t[j].l21;
            bool a4=a[i].l22<=t[j].l22;
            if(a1 && a2 && a3 && a4) ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
/*
2 1
aaba abaa
aaab baaa
aaabaa aabaaa
*/
