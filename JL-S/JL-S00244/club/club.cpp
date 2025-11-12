#include <bits/stdc++.h>
using namespace std;
int T;
const int N=2*1e4+4;
int st[N][4];
int roo[N];
//int sst[N][4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        long long ans=0;
        bool boo1=1,boo2=1;
        int n;
        int f=0,g=0,h=0;
        cin>>n;
        int li=n/2;
        for(int i=1;i<=n;i++){
            cin>>st[i][1]>>st[i][2]>>st[i][3];
            if(st[i][3])boo1=0;
            if(st[i][2])boo2=0;
            /*sst[i][1]=st[i][1];
            sst[i][2]=st[i][2];
            sst[i][3]=st[i][3];*/
            int ma=max(st[i][1],max(st[i][2],st[i][3]));
            if(ma==st[i][1]){
                f++;
                roo[i]=1;
            }
            else if(ma==st[i][2]){
                g++;
                roo[i]=2;
            }
            else if(ma==st[i][3]){
                h++;
                roo[i]=3;
            }
        }
        /*for(int i=1;i<n;i++){
            while(sst[i][1]<sst[i+1][1]){
                swap(sst[i][1],sst[i+1][1]);
                swap(sst[i][2],sst[i+1][2]);
                swap(sst[i][3],sst[i+1][3]);
            }
            if(sst[i][1]==sst[i][1]){
                while(sst[i][2]<sst[i+1][2]){
                    swap(sst[i][1],sst[i+1][1]);
                    swap(sst[i][2],sst[i+1][2]);
                    swap(sst[i][3],sst[i+1][3]);
                }
                if(sst[i][2]==sst[i+1][2]){
                    while(sst[i][3]<sst[i+1][3]){
                        swap(sst[i][1],sst[i+1][1]);
                        swap(sst[i][2],sst[i+1][2]);
                        swap(sst[i][3],sst[i+1][3]);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)cout<<sst[i][1]<<" "<<sst[i][2]<<" "<<sst[i][3]<<" "<<endl;*/
        if(boo1 && boo2){
            int op[N];
            for(int i=1;i<=n;i++)op[i]=st[i][1];
            sort(op+1,op+1+n);
            for(int i=n;i>li;i--)ans+=op[i];
            cout<<ans<<endl;
            continue;
        }
        while(f>li || g>li || h>li){
            if(f>li){
                int mi=0x3f3f3f3f;
                int k;
                for(int i=1;i<=n;i++){
                        if(roo[i]==1){
                        k=max(st[i][2],st[i][3]);
                        mi=min(st[i][1]-k,mi);
                    }
                }
                int x;
                for(int i=1;i<=n;i++){
                    if(roo[i]==1){
                        k=max(st[i][2],st[i][3]);
                        if(st[i][1]-k==mi){
                            x=i;
                            break;
                        }
                    }
                }
                f--;
                k=max(st[x][2],st[x][3]);
                if(k==st[x][2]){
                    g++;
                    roo[x]=2;
                }
                else if(k==st[x][3]){
                    h++;
                    roo[x]=3;
                }
            }

            if(g>li){
                int mi=0x3f3f3f3f;
                int k;
                for(int i=1;i<=n;i++){
                    if(roo[i]==2 ){
                        k=max(st[i][1],st[i][3]);
                        mi=min(st[i][2]-k,mi);
                    }
                }
                int x;
                for(int i=1;i<=n;i++){
                    if(roo[i]==2){
                        k=max(st[i][1],st[i][3]);
                        if(st[i][2]-k==mi){
                            x=i;
                            break;
                        }
                    }
                }
                g--;
                k=max(st[x][1],st[x][3]);
                if(k==st[x][1]){
                    f++;
                    roo[x]=1;
                }
                else if(k==st[x][3]){
                    h++;
                    roo[x]=3;
                }
            }

            if(h>li){
                int mi=0x3f3f3f3f;
                int k;
                for(int i=1;i<n;i++){
                    if(roo[i]==3){
                        k=max(st[i][2],st[i][1]);
                        mi=min(st[i][3]-k,mi);
                    }
                }
                int x;
                for(int i=1;i<=n;i++){
                    if(roo[i]==3){
                        k=max(st[i][2],st[i][1]);
                        if(st[i][3]-k==mi){
                            x=i;
                            break;
                        }
                    }
                }
                h--;
                k=max(st[x][2],st[x][1]);
                if(k==st[x][2]){
                    g++;
                    roo[x]=2;
                }
                else if(k==st[x][1]){
                    f++;
                    roo[x]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(roo[i]==1)ans+=st[i][1];
            else if(roo[i]==2)ans+=st[i][2];
            else if(roo[i]==3)ans+=st[i][3];
            //cout<<roo[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
I love CCF
I want to get a prize extremely
Please!!!
Thanks a lot!!!
*/
