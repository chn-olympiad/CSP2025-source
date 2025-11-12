
#include<bits/stdc++.h>
using namespace std;
int t,n,maxsum;
struct Node{
    int a,b,c;
};
Node nb[100010];
void solve(int x,int y,int z,int sum,int idx){
    if(idx>=n){
        maxsum=max(maxsum,sum);
        return;
    }else{
        idx++;
        if(x>=n/2){
            y++;
            sum+=nb[idx].b;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].b;
            y--;
            z++;
            sum+=nb[idx].c;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].c;
            x--;
        }else if(y>=n/2){
            x++;
            sum+=nb[idx].a;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].a;
            x--;
            z++;
            sum+=nb[idx].c;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].c;
            z--;
        }else if(z>=n/2){
            x++;
            sum+=nb[idx].a;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].a;
            x--;
            y++;
            sum+=nb[idx].b;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].b;
            y--;
        }else{
            x++;
            sum+=nb[idx].a;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].a;
            x--;
            y++;
            sum+=nb[idx].b;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].b;
            y--;
            z++;
            sum+=nb[idx].c;
            solve(x,y,z,sum,idx);
            sum-=nb[idx].c;
            z--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nb[i].a>>nb[i].b>>nb[i].c;
        }
        maxsum=0;
        solve(0,0,0,0,0);
        cout<<maxsum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
