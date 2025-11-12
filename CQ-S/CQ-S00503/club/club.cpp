#include<bits/stdc++.h>
using namespace std;

struct L{
    int a,b,c;
};

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        int cnt[3]={0,0,0};
        cin>>n;
        long long int v[3]={0,0,0};
        int ls[3][n];
        L l[n];
        for(int i=0;i<n;i++){
            cin>>l[i].a>>l[i].b>>l[i].c;
            if(l[i].a==max(l[i].a,max(l[i].b,l[i].c))){
                v[0]+=l[i].a;
                ls[0][cnt[0]++]=i;
            }else if(l[i].b==max(l[i].a,max(l[i].b,l[i].c))){
                v[1]+=l[i].b;
                ls[1][cnt[1]++]=i;
            }else{
                v[2]+=l[i].c;
                ls[2][cnt[2]++]=i;
            }
        }
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<cnt[i];j++){
        //         cout<<ls[i][j]<<" ";
        //     }cout<<endl;
        // }
        bool flag=1;
        for(int i=0;i<3;i++){
            if(cnt[i]>n/2){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<v[0]+v[1]+v[2]<<endl;
            continue;
        }
        //非理想
        for(int k=0;k<3;k++){
            if(cnt[k]>n/2){
                // for(int i=0;i<cnt[k]-n/2;i++){
                    int minn[3][cnt[k]];
                    //初始化
                    for(int j=0;j<cnt[k];j++){
                        minn[0][j]=-1;
                        minn[1][j]=-1;
                        minn[2][j]=-1;
                    }
                    //
                    for(int j=0;j<cnt[k];j++){
                            int now=ls[k][j];
                            int f1=true,f2=true;
                        for(int m=0;m<cnt[k]-n/2;m++){
                            if(now==-1){
                                now=ls[k][j];
                            }
                            // for(int i=0;i<3;i++){
                            //     if(m)
                            // }
                            //k=0 k2 12

                            //找从k到abc的最小损耗
                            if(k==0){
                                if((minn[1][m]==-1 or l[minn[1][m]].a-l[minn[1][m]].b>l[ls[k][now]].a-l[ls[k][now]].b) and f1){
                                    int aaaa=now;
                                    now=minn[1][m];
                                    minn[1][m]=aaaa;
                                }else{
                                    if(l[minn[1][m]].b-l[minn[1][m]].a!=l[ls[k][now]].b-l[ls[k][now]].a)
                                    f1=false;
                                    else{
                                        if(m!=0 and now!=minn[1][m-1]){
                                            int aaaa=now;
                                            now=minn[1][m];
                                            minn[1][m]=aaaa;
                                        }
                                    }
                                }
                                if((minn[2][m]==-1 or l[minn[2][m]].a-l[minn[2][m]].c>l[ls[k][now]].a-l[ls[k][now]].c) and f2){
                                    int aaaa=now;
                                    now=minn[2][m];
                                    minn[2][m]=aaaa;
                                }else{if(l[minn[2][m]].b-l[minn[2][m]].c!=l[ls[k][now]].b-l[ls[k][now]].c)
                                    f2=false;
                                    else{
                                        if(m!=0 and now!=minn[2][m-1]){
                                            int aaaa=now;
                                            now=minn[2][m];
                                            minn[2][m]=aaaa;
                                        }
                                    }
                                }
                            }else if(k==1){
                                if((minn[0][m]==-1 or l[minn[0][m]].b-l[minn[0][m]].a>l[ls[k][now]].b-l[ls[k][now]].a) and f1){
                                    int aaaa=now;
                                    now=minn[0][m];
                                    minn[0][m]=aaaa;
                                    // cout<<"!"<<j<<" "<<m<<":"<<k<<" "<<cnt[k]<<" "<<now<<" "<<minn[0][m]<<" "<<ls[k][j]<<" "<<aaaa<<endl;
                                }else{
                                    if(l[minn[0][m]].b-l[minn[0][m]].a!=l[ls[k][now]].b-l[ls[k][now]].a)
                                    f1=false;
                                    else{
                                        if(m!=0 and now!=minn[0][m-1]){
                                            int aaaa=now;
                                            now=minn[0][m];
                                            minn[0][m]=aaaa;
                                            // cout<<"@"<<j<<" "<<m<<":"<<k<<" "<<cnt[k]<<" "<<now<<" "<<minn[0][m]<<" "<<ls[k][j]<<" "<<aaaa<<endl;
                                        }
                                    }
                                }
                                if((minn[2][m]==-1 or l[minn[2][m]].b-l[minn[2][m]].c>l[ls[k][now]].b-l[ls[k][now]].c) and f2){
                                    int aaaa=now;
                                    now=minn[2][m];
                                    minn[2][m]=aaaa;
                                    // cout<<"#"<<j<<" "<<m<<":"<<k<<" "<<cnt[k]<<" "<<now<<" "<<minn[2][m]<<" "<<ls[k][j]<<" "<<aaaa<<endl;
                                }else{
                                    if(l[minn[2][m]].b-l[minn[2][m]].c!=l[ls[k][now]].b-l[ls[k][now]].c)
                                    f2=false;
                                    else{
                                        if(m!=0 and now!=minn[2][m-1]){
                                            int aaaa=now;
                                            now=minn[2][m];
                                            minn[2][m]=aaaa;
                                            // cout<<"$"<<j<<" "<<m<<":"<<k<<" "<<cnt[k]<<" "<<now<<" "<<minn[2][m]<<" "<<ls[k][j]<<" "<<aaaa<<endl;
                                        }
                                    }
                                }
                            }else{
                                if((minn[1][m]==-1 or l[minn[1][m]].c-l[minn[1][m]].b>l[ls[k][now]].c-l[ls[k][now]].b) and f1){
                                    int aaaa=now;
                                    now=minn[1][m];
                                    minn[1][m]=aaaa;
                                }else{
                                    if(l[minn[1][m]].b-l[minn[1][m]].a!=l[ls[k][now]].b-l[ls[k][now]].a)
                                    f1=false;
                                    else{
                                        if(m!=0 and now!=minn[1][m-1]){
                                            int aaaa=now;
                                            now=minn[1][m];
                                            minn[1][m]=aaaa;
                                        }
                                    }
                                }
                                if((minn[0][m]==-1 or l[minn[0][m]].c-l[minn[0][m]].a>l[ls[k][now]].c-l[ls[k][now]].a) and f2){
                                    int aaaa=now;
                                    now=minn[0][m];
                                    minn[0][m]=aaaa;
                                }else{
                                    if(l[minn[0][m]].b-l[minn[0][m]].c!=l[ls[k][now]].b-l[ls[k][now]].c)
                                    f2=false;
                                    else{
                                        if(m!=0 and now!=minn[0][m-1]){
                                            int aaaa=now;
                                            now=minn[0][m];
                                            minn[0][m]=aaaa;
                                        }
                                    }
                                }
                            }
                        }
                        // cout<<endl;
                    }
                    int nnn=cnt[k]-n/2;
                    // cout<<k<<endl;
                    // for(int i=0;i<3;i++){
                    //     cout<<i<<":";
                    //     for(int j=0;j<nnn;j++){
                    //         cout<<minn[i][j]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    if(k==0){
                        //1 2
                        int a=0,b=0;
                        for(int j=0;j<nnn;j++){
                            if(l[minn[1][a]].a-l[minn[1][a]].b<l[minn[2][b]].a-l[minn[2][b]].c and cnt[1]<n/2){
                                cnt[1]++;
                                v[0]-=l[a].a;
                                v[1]+=l[a].b;
                                cnt[0]--;
                                a++;
                            }else if(l[minn[1][a]].a-l[minn[1][a]].b>l[minn[2][b]].a-l[minn[2][b]].c and cnt[2]<n/2){
                                cnt[2]++;
                                cnt[0]--;
                                v[0]-=l[b].a;
                                v[2]+=l[b].c;
                                b++;
                            }
                        }
                    }else if(k==1){
                            // cout<<1<<endl;
                        //0 2
                        int a=0,b=0;
                        bool fls[n]={0};
                        for(int j=0;j<nnn;j++){
                            // if(a>=n or b){

                            // }
                            // cout<<nnn<<" "<<l[minn[0][a]].b-l[minn[0][a]].a<<" "<<l[minn[2][b]].b-l[minn[2][b]].c<<" "<<cnt[0]<<" "<<cnt[2]<<endl<<endl;
                            if(l[minn[0][a]].b-l[minn[0][a]].a<=l[minn[2][b]].b-l[minn[2][b]].c and cnt[0]<n/2){
                                cnt[0]++;
                                cnt[1]--;
                                v[0]+=l[a].a;
                                v[1]-=l[a].b;
                                a++;
                                // cout<<'!';
                                
                                if(minn[0][a]==minn[2][b]){
                                    b++;
                                }
                            }else if(l[minn[0][a]].a-l[minn[0][a]].b>=l[minn[2][b]].a-l[minn[2][b]].c and cnt[2]<n/2){
                                cnt[2]++;
                                cnt[1]--;
                                v[1]-=l[b].a;
                                v[2]+=l[b].c;
                                b++;
                                // cout<<'@';
                                if(minn[0][a]==minn[2][b]){
                                    a++;
                                }
                            }
                        }

                    }else{
                        //0 1
                        int a=0,b=0;
                        for(int j=0;j<nnn;j++){
                            if(l[minn[0][a]].c-l[minn[0][a]].a<l[minn[1][b]].c-l[minn[1][b]].b and cnt[0]<n/2){
                                cnt[0]++;
                                cnt[2]--;
                                v[2]-=l[a].a;
                                v[0]+=l[a].b;
                                a++;
                            }else if(l[minn[0][a]].a-l[minn[0][a]].b>l[minn[1][b]].a-l[minn[1][b]].c and cnt[1]<n/2){
                                cnt[1]++;
                                cnt[2]--;
                                v[2]-=l[b].a;
                                v[1]+=l[b].c;
                                b++;
                            }
                        }

                    }
                // }
            }
        }
        cout<<v[0]+v[1]+v[2];
        // cout<<" "<<v[0]<<" "<<v[1]<<" "<<v[2];
        cout<<endl;
    }

return 0;
} 
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

/*

ls[3][n]
   i  j
第i个职业里的人的序号为ls[i][j]


*/