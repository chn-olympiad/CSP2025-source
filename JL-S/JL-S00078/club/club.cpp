#include<bits/stdc++.h>
using namespace std;
int t,n[100005][4],m[4][100005],f[4],s=0,q=0,a;
int main(){
    freopen("club.in","r",stdin);
    cin>>t;
    for(int z=0;z<t;z++){
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>n[i][1];
            cin>>n[i][2];
            cin>>n[i][3];
            if(n[i][2]<n[i][1])
                m[1][n[i][1]-n[i][2]]++;
            else
                m[1][n[i][2]-n[i][1]]++;
            if(n[i][3]<n[i][1])
                m[2][n[i][1]-n[i][3]]++;
            else
                m[2][n[i][3]-n[i][1]]++;
            if(n[i][2]<n[i][3])
                m[3][n[i][3]-n[i][2]]++;
            else
                m[3][n[i][2]-n[i][3]]++;
            if(n[i][1]>=n[i][3]&&n[i][1]>=n[i][2]){
                s+=n[i][1];
                f[1]++;
            }
            else if(n[i][2]>=n[i][3]&&n[i][1]<=n[i][2]){
                s+=n[i][2];
                f[2]++;
            }
            else{
                s+=n[i][3];
                f[3]++;
            }
            if(f[1]>a/2){
                while(m[1][q]==0&&m[2][q]==0)
                    q++;
                s-=q;
                if(m[1][q]==0){
                    m[2][q]--;
                }
                else{
                    m[1][q]--;
                }
                q=0;
                f[1]--;
            }
            else if(f[2]>a/2){
                while(m[3][q]==0&&m[1][q]==0)
                    q++;
                s-=q;
                if(m[1][q]==0){
                    m[3][q]--;
                }
                else{
                    m[1][q]--;
                }
                q=0;
                f[2]--;
            }
           else  if(f[3]>a/2){
                while(m[3][q]==0&&m[2][q]==0)
                    q++;
                s-=q;
                if(m[3][q]==0){
                    m[2][q]--;
                }
                else{
                    m[3][q]--;
                }
                q=0;
                f[3]--;
            }
        }
        cout<<s<<endl;
        freopen("club.out","w",stdout);
        s=0;
        for(int i=0;i<a;i++){
            m[1][i]=0;
            m[2][i]=0;
            m[3][i]=0;
        }
        f[1]=0;
        f[3]=0;
        f[2]=0;
    }
    return 0;
}
