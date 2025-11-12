#include<bits/stdc++.h>
using namespace std;
int qm(int a,int b){
    int w=a;
    for(int l=1;l<=b;l++){
        a=a*w;
    }
    return a;
}
int sort(int u,int v){
    int r;
    r=u;
    u=v;
    v=r;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt=0,ans=0;
    cin>>n>>m;
    int s,i[n];
    cin>>s;
    int o[n],p[n];
    for(int j=1;j<=size.s();j++){
        if(j!=size.s()){
            o[size.s()-1*j]=s%qm(10,j);
            s=s-s%qm(10,j);
        }
        else{
            o[size.s()-1*j]=s/qm(10,j);
        }
    }
    for(int e=0;e<n;e++){
        cin>>i[e];
    }
    int nogo=0;
    p[0]=i[0];
    p[n]=i[n];
    while(p[0]!=i[0]&&p[n]!=i[n]){
        while(cnt<m){
            for(int f=0;f<n;f++){
                if(i[f]=-1){
                    nogo++;
                }
                else{
                    if(f!=n){
                        sort(i[f],i[f+1]);
                    }
                    if(o[f]=0){
                        cnt++;
                    }
                    else{
                        nogo++;
                        if(i[f+1]=nogo){
                            i[f+1]=-1;
                            nogo++;
                        }
                    }
                }
            }
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
