#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;

        int m[n][3],ca[n][3],bj[3]={0},ans=0,f=n/2,bj2[n]={0};
        for(int i=0;i<n;i++){
            int mi=INT_MAX;
            for(int j=0;j<3;j++){
                cin>>m[i][j];
                if(m[i][j]<mi)mi=m[i][j];
            }
            for(int j=0;j<3;j++){
                ca[i][j]=m[i][j]-mi;
            }

        }

        for(int k=n;k;k--){
            int tmp=INT_MIN,p[2],a=INT_MIN;
            for(int i=0;i<n;i++){
                for(int j=0;j<3;j++){
                    if(bj[j]<f&&bj2[i]==0){
                        if(ca[i][j]>tmp){
                            p[0]=i;
                            p[1]=j;
                            tmp=ca[i][j];
                            a=m[i][j];
                        }

                    }

                }

            }

            ans+=a;
            ca[p[0]][p[1]]=INT_MAX;
            bj[p[1]]+=1;
            bj2[p[0]]=1;
        }

        cout<<ans;
        if(t)cout<<endl;


    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
