#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a[128001],b[128001];
    string a1,b1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<q;i++){
        cin>>a1>>b1;
        string c,d;
        string c1,c2;
        int cnt=0;
        for(int j=0;j<a1.size();j++){
            for(int k=a1.size()-1;k>=0;k--){
                c="";
                c1="";
                c2="";
                d="";
                for(int p=0;p<j;p++){
                    c1+= a1[p];
                }
                for(int p=k+1;p<a1.size();p++){
                    c2+= a1[p];
                }
                for(int p=j;p<=k;p++){
                    c+=a1[p];
                    d+=b1[p];
                }
                for(int p=0;p<n;p++){
                    if(c==a[p]&&b[p]==d){
                        if(c1+b[p]+c2==b1){
                            cnt++;
                        }

                    }
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
