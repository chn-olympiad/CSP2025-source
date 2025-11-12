#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int m,n;
    cin>>m>>n;
    string st[m][2];
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>st[i][j];
        }
    }
    int ans1[n];
    for(int i=0;i<n;i++){
        int ans=0;
        string a,b;
        cin>>a>>b;
        int s=-1,s1=-1;
        for(int p=0;p<a.length();p++){
            if(a[p]!=b[p]){
                s=p;
                if(s1==-1){
                    s1=s;
                }
            }
        }
        for(int p=0;p<=s1;p++){
            for(int q=s;q<=a.length();q++){
                string k,k1;
                for(int j=p;j<=q;j++){
                    k+=a[j];
                    k1+=b[j];
                }
                for(int r=0;r<m;r++){
                    if(st[r][0]==k&&st[r][1]==k1){
                        ans++;
                    }
                }
            }
        }
        ans1[i]=ans;
    }
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<endl;
    }
    return 0;
}
