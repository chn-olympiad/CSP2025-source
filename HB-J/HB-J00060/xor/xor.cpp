#include <bits/stdc++.h>
using namespace std;
// Passed testpoints until 12
// approximated score : 60

struct seg{
    int a;
    int b;

};
seg s[2000005];
int f[2000005];
int val[2000005];
int fro[2000005];

bool cmps(seg i,seg j){
    return i.a<j.a;
}

bool check(seg i,seg j){
    return j.a>i.b;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    int rks;
    cin>>n>>rks;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        fro[i]=fro[i-1]^val[i];
    }
    int ptr=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if((fro[i]^fro[j-1])==rks){
                //cerr << j << " " << i << " " <<  (fro[i]^fro[j-1]) << "\n";
                s[ptr].a=j;
                s[ptr].b=i;
                ptr++;
            }
        }
    }
    int k=ptr;
    sort(s,s+k,cmps);
    for(int i=0;i<k;i++){
        //cerr<< "A";
        f[i]=1;
        for(int j=0;j<i;j++){
            //cerr<< "B";
            if(check(s[j],s[i])){
                //cerr << "terith";
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int maxf=-1;
    for(int i=0;i<k;i++){
        maxf=max(maxf,f[i]);
    }
    cout << maxf;
    return 0;
}
//803 ROOM 22 COMPUTER IN HUST,WUHAN
//cspj2025
