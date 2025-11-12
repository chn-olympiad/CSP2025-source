#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+50;

int siz(string s_){
    string s = s_;
    int cnt=0;
    for(int i =0;s[i]!='b';i++){
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("replace4.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n ,q;
    cin>>n>>q;

    int fro1[MAXN];
    int bac1[MAXN];
    int fro2[MAXN];
    int bac2[MAXN];


    for(int i =0;i<2*n;i+=2){
        string s1,s2;
        cin>>s1>>s2;
        fro1[i] = siz(s1);
        fro1[i+1] = siz(s2);
        bac1[i] = s1.size()-(siz(s1))-1;
        bac1[i+1] = s2.size()-(siz(s2))-1;
    }

    for(int i =0;i<2*q;i+=2){
        string t1,t2;
        cin>>t1>>t2;
        fro2[i] = siz(t1);
        fro2[i+1] = siz(t2);
        bac2[i] = t1.size()-(siz(t1))-1;
        bac2[i+1] = t2.size()-(siz(t2))-1;

        int ans=0;
        for(int j =0;j<2*n;j+=2){
            if((fro1[j]<=fro2[i])&&(fro1[j+1]<=fro2[i])&&(bac1[j]<=bac2[i])&&(bac1[j+1]<=bac2[i])&&(fro1[j]<=fro2[i+1])&&(fro1[j+1]<=fro2[i+1])&&(bac1[j]<=bac2[i+1])&&(bac1[j+1]<=bac2[i+1])){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
