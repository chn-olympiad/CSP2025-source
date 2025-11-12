#include<bits/stdc++.h>
using namespace std;
int s[10000];
int seat[10000][10000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
            cin>>s[i];
    }
    int xing_ye=s[1];
    for(int i=1;i<=m*n-1;i++){
        for(int j=i+1;j<=n*m;j++){
            if(s[i]<s[j]){
                int tmp;
                tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    int x=1,y=1;
    int z=1,did=0,dio=0;
    int ans=0;
    while(z<=m*n){
        if(m==1){
            ans=s[z];
            seat[1][y]=ans;
            if(ans==xing_ye){
                cout<<" "<<1<<" "<<y<<" ";
                break;
            }
            y++;z++;
        }
         if(n==1){
            ans=s[z];
            seat[x][1]=ans;
            if(ans==xing_ye){
                cout<<" "<<x<<" "<<1<<" ";
                break;
            }
            x++;z++;
        }
        if(did==0 && x!=m){
            ans=s[z];
            seat[x][y]=ans;
            if(ans==xing_ye){
            cout<<" "<<y<<" "<<x<<" ";
            break;
            }
            x++;z++;
        }
        else if(did==0 && x==m){
                ans=s[z];
                seat[x][y]=ans;
                if(ans==xing_ye){
                    cout<<" "<<y<<" "<<x<<" ";
                break;
            }
                y++;did=1;z++;
                ans=s[z];
                seat[x][y]=ans;
                if(ans==xing_ye){
                    cout<<" "<<y<<" "<<x<<" ";
                break;
            }
                x--;z++;
            }
        else if(did==1 && x!=1){
                ans=s[z];
                seat[x][y]=ans;
                if(ans==xing_ye){
                    cout<<" "<<y<<" "<<x<<" ";
                    break;
                }
                x--;z++;
            }
        else    if(did==1 && x==1){
                    ans=s[z];
                    seat[x][y]=ans;
                if(ans==xing_ye){
                    cout<<" "<<y<<" "<<x<<" ";
                    break;
                }
                y++;did=0;z++;
                ans=s[z];
                seat[x][y]=ans;
                if(ans==xing_ye){
                    cout<<" "<<y<<" "<<x<<" ";
                    break;
                }
                x++;z++;
        }

    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<seat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

