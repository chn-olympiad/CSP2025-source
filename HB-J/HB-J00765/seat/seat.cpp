#include<bits/stdc++.h>
using namespace std;
int s[100001],mp[101][101],flag=1,ans=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    a=s[1];
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        if(flag==1){
            for(int j=1;j<=m;j++){
                mp[i][j]=s[ans];
                //cout<<s[ans]<<endl;
                ans++;
            }
            flag=0;
        }else{
            for(int j=m;j>=1;j--){
                mp[i][j]=s[ans];
                //cout<<s[ans]<<endl;
                ans++;
            }

            flag=1;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    flag=1;
    for(int i=1;i<=n;i++){
        if(flag==1){
            for(int j=1;j<=m;j++){
                if(mp[i][j]==a){
                    cout<<i<<" "<<j;
                    return 0;
                }
                //cout<<i<<" "<<j<<endl;
            }
            flag=0;
        }else{
            for(int j=m;j>=1;j--){
                if(mp[i][j]==a){
                    cout<<i<<" "<<j;
                    return 0;
                }
                //cout<<i<<" "<<j<<endl;
            }

            flag=1;
        }
    }


    return 0;
}



