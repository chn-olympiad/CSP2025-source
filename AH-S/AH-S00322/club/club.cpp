#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,z;
}a[100005];
bool cmp(node s,node t){
    int ss=max(s.x,max(s.y,s.z)),tt=max(t.x,max(t.y,t.z));
    int ss1=s.x+s.y+s.z-max(s.x,max(s.y,s.z))-min(s.x,min(s.y,s.z));
    int tt1=t.x+t.y+t.z-max(t.x,max(t.y,t.z))-min(t.x,min(t.y,t.z));
    if(ss-ss1!=tt-tt1){
        return ss-ss1>tt-tt1;
    }
    return ss>tt;
}
int t,n;
int dfs(int i,int x,int y,int z,int sum){
    int ans=-1;
    if(i>n){
        return sum;
    }
    if(x<n/2){
        ans=max(ans,dfs(i+1,x+1,y,z,sum+a[i].x));
    }
    if(y<n/2){
        ans=max(ans,dfs(i+1,x,y+1,z,sum+a[i].y));
    }
    if(z<n/2){
        ans=max(ans,dfs(i+1,x,y,z+1,sum+a[i].z));
    }
    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        if(n<=10){
            cout<<dfs(1,0,0,0,0)<<"\n";
        }else{
            sort(a+1,a+n+1,cmp);
            int u,v,w,ans;
            u=v=w=ans=0;
            for(int i=1;i<=n;i++){
                if(a[i].x>max(a[i].y,a[i].z)){
                    if(u<n/2){
                        u++;
                        ans+=a[i].x;
                    }else{
                        if(a[i].y>a[i].z&&v<n/2){
                            v++;
                            ans+=a[i].y;
                        }else if(a[i].y==a[i].z&&v<n/2&&w<n/2){
                            int s=i;
                            while(1){
                                s++;
                                if(a[s].y>a[s].z){
                                    v++;
                                    ans+=a[i].y;
                                    break;
                                }else if(a[s].z>a[s].y){
                                    w++;
                                    ans+=a[i].z;
                                    break;
                                }
                            }
                        }else{
                            w++;
                            ans+=a[i].z;
                        }
                    }
                }else if(a[i].y>max(a[i].x,a[i].z)){
                    if(v<n/2){
                        v++;
                        ans+=a[i].y;
                    }else{
                        if(a[i].x>a[i].z&&u<n/2){
                            u++;
                            ans+=a[i].x;
                        }else if(a[i].x==a[i].z&&u<n/2&&w<n/2){
                            int s=i;
                            while(1){
                                s++;
                                if(a[s].z>a[s].x){
                                    w++;
                                    ans+=a[i].z;
                                    break;
                                }else if(a[s].x>a[s].z){
                                    u++;
                                    ans+=a[i].x;
                                    break;
                                }
                            }
                        }else{
                            w++;
                            ans+=a[i].z;
                        }
                    }
                }else if(a[i].z>max(a[i].y,a[i].x)){
                    if(w<n/2){
                        w++;
                        ans+=a[i].z;
                    }else{
                        if(a[i].y>a[i].x&&v<n/2){
                            v++;
                            ans+=a[i].y;
                        }else if(a[i].y==a[i].x&&v<n/2&&u<n/2){
                            int s=i;
                            while(1){
                                s++;
                                if(a[s].y>a[s].x){
                                    v++;
                                    ans+=a[i].y;
                                    break;
                                }else if(a[s].x>a[s].y){
                                    u++;
                                    ans+=a[i].x;
                                    break;
                                }
                            }
                        }else{
                            u++;
                            ans+=a[i].x;
                        }
                    }
                }else{
                    if(a[i].x==a[i].y==a[i].z){
                        if(u<n/2){
                            u++;
                            ans+=a[i].x;
                        }else if(v<n/2){
                            v++;
                            ans+=a[i].y;
                        }else{
                            w++;
                            ans+=a[i].z;
                        }
                    }else if(a[i].x==a[i].y){
                        if(u<n/2){
                            u++;
                            ans+=a[i].x;
                        }else if(v<n/2){
                            v++;
                            ans+=a[i].y;
                        }
                    }else if(a[i].x==a[i].z){
                        if(u<n/2){
                            u++;
                            ans+=a[i].x;
                        }else if(v<n/2){
                            w++;
                            ans+=a[i].z;
                        }
                    }else if(a[i].z==a[i].y){
                        if(v<n/2){
                            v++;
                            ans+=a[i].y;
                        }else{
                            w++;
                            ans+=a[i].z;
                        }
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
return 0;
}
