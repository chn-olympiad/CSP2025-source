#include <bits/stdc++.h>

using namespace std;
int t,n,x,y,m,b;
int a[10005][10005];
int s[10005];
int k[10005];
int main()
{
    freopen("problem.in","r",stdin);
    freopen("problem.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            x=a[i][1],y=a[i][2],m=a[i][3];
            b=max(max(x,y),max(x,m));
            if(b==x){
                if(k[1]==n/2){
                    b=max(y,m);
                    if(b==y){
                        k[2]+=1;
                        s[q]+=y;
                        continue;
                    }
                    else{
                        k[3]+=1;
                        s[q]+=m;
                        continue;
                    }
                }
                k[1]+=1;
                s[q]+=x;
                continue;
            }
            else if(b==y){
                if(k[2]==n/2){
                    b=max(x,m);
                    if(b==x){
                        k[1]+=1;
                        s[q]+=x;
                        continue;
                    }
                    else{
                        k[3]+=1;
                        s[q]+=m;
                        continue;
                    }
                }
                k[2]+=1;
                s[q]+=y;
            }
            else{
                if(k[3]==n/2){
                    b=max(y,x);
                    if(b==y){
                        k[2]+=1;
                        s[q]+=y;
                        continue;
                    }
                    else{
                        k[1]+=1;
                        s[q]+=x;
                        continue;
                    }
                }
                k[3]+=1;
                s[q]+=m;
            }
        }
        k[1]=0,k[2]=0,k[3]=0;
        x=0,y=0,m=0;
    }
    for(int i=1;i<=t;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
