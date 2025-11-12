#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4];
long long cnt;
struct node{
    int x,y;
    bool operator <(const node &a)const
    {
        return a.x<x;
    }
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        priority_queue<node> q[4];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            int ax=max(a[i][1],max(a[i][2],a[i][3]));
            if(a[i][1]==ax){
                bool ok=0;
                if(q[1].size()>=n/2){
                    node p=q[1].top();
                    if(p.x>a[i][1]-max(a[i][2],a[i][3])){
                        ok=1;
                        if(a[i][2]>a[i][3]){
                            q[2].push({a[i][2]-max(a[i][1],a[i][3]),i});
                            cnt+=a[i][2];
                        }else{
                            cnt+=a[i][3];
                            q[3].push({a[i][3]-max(a[i][2],a[i][1]),i});
                        }
                    }else{
                        int ip=p.y;
                        q[1].pop();
                        cnt-=a[ip][1];
                        if(a[ip][2]>a[ip][3]){
                            cnt+=a[ip][2];
                            q[2].push({a[ip][2]-max(a[ip][1],a[ip][3]),ip});
                        }else{
                            cnt+=a[ip][3];
                            q[3].push({a[ip][3]-max(a[ip][2],a[ip][1]),ip});
                        }
                    }
                }
                if(ok==0){
                    cnt+=a[i][1];
                    q[1].push({a[i][1]-max(a[i][2],a[i][3]),i});
                }
            }else if(a[i][2]==ax){
                bool ok=0;
                if(q[2].size()>=n/2){
                    node p=q[2].top();
                    if(p.x>a[i][2]-max(a[i][1],a[i][3])){
                        ok=1;
                        if(a[i][1]>a[i][3]){
                            q[1].push({a[i][2]-max(a[i][1],a[i][3]),i});
                            cnt+=a[i][1];
                        }else{
                            cnt+=a[i][3];
                            q[3].push({a[i][3]-max(a[i][1],a[i][2]),i});
                        }
                    }else{
                        int ip=p.y;
                        q[2].pop();
                        cnt-=a[ip][2];
                        if(a[ip][1]>a[ip][3]){
                            cnt+=a[ip][1];
                            q[1].push({a[ip][1]-max(a[ip][1],a[ip][3]),ip});
                        }else{
                            cnt+=a[ip][3];
                            q[3].push({a[ip][3]-max(a[ip][1],a[ip][2]),ip});
                        }
                    }
                }
                if(ok==0){
                    cnt+=a[i][2];
                    q[2].push({a[i][2]-max(a[i][1],a[i][3]),i});
                }
            }else{
                bool ok=0;
                if(q[3].size()>=n/2){
                    node p=q[3].top();
                    if(p.x>a[i][3]-max(a[i][2],a[i][1])){
                        ok=1;
                        if(a[i][2]>a[i][1]){
                            q[2].push({a[i][2]-max(a[i][1],a[i][3]),i});
                            cnt+=a[i][2];
                        }else{
                            cnt+=a[i][1];
                            q[1].push({a[i][1]-max(a[i][2],a[i][3]),i});
                        }
                    }else{
                        int ip=p.y;
                        q[3].pop();
                        cnt-=a[ip][3];
                        if(a[ip][2]>a[ip][1]){
                            cnt+=a[ip][2];
                            q[2].push({a[ip][2]-max(a[ip][1],a[ip][3]),ip});
                        }else{
                            cnt+=a[ip][1];
                            q[1].push({a[ip][1]-max(a[ip][2],a[ip][1]),ip});
                        }
                    }
                }
                if(ok==0){
                    cnt+=a[i][3];
                    q[3].push({a[i][3]-max(a[i][2],a[i][1]),i});
                }
            }
        }
        cout<<cnt<<endl;
        cnt=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
