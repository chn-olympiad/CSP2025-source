#include<bits/stdc++.h>
using namespace std;
string tp[200001][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>tp[i][0]>>tp[i][1];
    while(q--){
        string a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=1;i<=n;i++){
            int fa=a.find(tp[i][0]),fb=b.find(tp[i][1]);
            if(fa!=-1&&fb!=-1&&fa==fb){
                string aa=a;
                for(int j=0;j<tp[i][0].size();j++){
                    aa[fa+j]=tp[i][1][j];
                }
            ans+=(aa==b);
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
