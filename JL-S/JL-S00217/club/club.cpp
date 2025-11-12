#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,a[3];
    int fmx,smx,sid,fid,tid,tmx;
    bool fsflag=0,stflag=0;
}per[100006];
struct cl{
    int good,id;
}ac[3][100006];
bool cmp(cl x,cl y){
    return x.good>y.good;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt[3]={0,0,0};
        memset(ac[0],0,100006);
        memset(ac[1],0,100006);
        memset(ac[2],0,100006);
        for(int i=0;i<n;i++){
            cin>>per[i].a[0]>>per[i].a[1]>>per[i].a[2];
            per[i].id=i;
            if(per[i].a[0]>=per[i].a[1]&&per[i].a[0]>=per[i].a[2]){
                per[i].fmx=per[i].a[0];
                per[i].fid=0;
                if(per[i].a[0]==per[i].a[1]){
                    per[i].smx=per[i].a[1];
                    per[i].sid=1;
                    per[i].fsflag=1;
                    if(per[i].a[1]==per[i].a[2]){
                        per[i].tmx=per[i].a[2];
                        per[i].tid=2;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[2];
                        per[i].tid=2;
                    }
                }
                else if(per[i].a[0]==per[i].a[2]){
                    per[i].smx=per[i].a[2];
                    per[i].sid=2;
                    per[i].fsflag=1;
                    if(per[i].a[2]==per[i].a[1]){
                        per[i].tmx=per[i].a[1];
                        per[i].tid=1;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[1];
                        per[i].tid=1;
                    }
                }
                else if(per[i].a[2]==per[i].a[1]){
                    per[i].smx=per[i].a[2];
                    per[i].sid=2;
                    per[i].tmx=per[i].a[1];
                    per[i].tid=1;
                    per[i].stflag=1;
                }
                else if(per[i].a[1]>per[i].a[2]){
                    per[i].smx=per[i].a[1];
                    per[i].sid=1;
                    per[i].tmx=per[i].a[2];
                    per[i].tid=2;
                }
                else if(per[i].a[2]>per[i].a[1]){
                    per[i].smx=per[i].a[2];
                    per[i].sid=2;
                    per[i].tmx=per[i].a[1];
                    per[i].tid=1;
                }
            }
            else if(per[i].a[1]>=per[i].a[2]&&per[i].a[1]>=per[i].a[0]){
                per[i].fmx=per[i].a[1];
                per[i].fid=1;
                if(per[i].a[1]==per[i].a[0]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].fsflag=1;
                    if(per[i].a[0]==per[i].a[2]){
                        per[i].tmx=per[i].a[2];
                        per[i].tid=2;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[2];
                        per[i].tid=2;
                    }
                }
                else if(per[i].a[1]==per[i].a[2]){
                    per[i].smx=per[i].a[2];
                    per[i].sid=2;
                    per[i].fsflag=1;
                    if(per[i].a[2]==per[i].a[0]){
                        per[i].tmx=per[i].a[0];
                        per[i].tid=0;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[0];
                        per[i].tid=0;
                    }
                }
                else if(per[i].a[0]==per[i].a[2]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].tmx=per[i].a[2];
                    per[i].tid=2;
                    per[i].stflag=1;
                }
                else if(per[i].a[0]>per[i].a[2]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].tmx=per[i].a[2];
                    per[i].tid=2;
                }
                else if(per[i].a[2]>per[i].a[0]){
                    per[i].smx=per[i].a[2];
                    per[i].sid=2;
                    per[i].tmx=per[i].a[0];
                    per[i].tid=0;
                }
            }
            else if(per[i].a[2]>=per[i].a[0]&&per[i].a[2]>=per[i].a[1]){
                per[i].fmx=per[i].a[2];
                per[i].fid=2;
                if(per[i].a[2]==per[i].a[1]){
                    per[i].smx=per[i].a[1];
                    per[i].sid=1;
                    per[i].fsflag=1;
                    if(per[i].a[1]==per[i].a[0]){
                        per[i].tmx=per[i].a[0];
                        per[i].tid=0;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[0];
                        per[i].tid=0;
                    }
                }
                else if(per[i].a[2]==per[i].a[0]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].fsflag=1;
                    if(per[i].a[0]==per[i].a[1]){
                        per[i].tmx=per[i].a[1];
                        per[i].tid=1;
                        per[i].stflag=1;
                    }
                    else{
                        per[i].tmx=per[i].a[1];
                        per[i].tid=1;
                    }
                }
                else if(per[i].a[0]==per[i].a[1]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].tmx=per[i].a[1];
                    per[i].tid=1;
                    per[i].stflag=1;
                }
                else if(per[i].a[1]>per[i].a[0]){
                    per[i].smx=per[i].a[1];
                    per[i].sid=1;
                    per[i].tmx=per[i].a[0];
                    per[i].tid=0;
                }
                else if(per[i].a[0]>per[i].a[1]){
                    per[i].smx=per[i].a[0];
                    per[i].sid=0;
                    per[i].tmx=per[i].a[1];
                    per[i].tid=1;
                }
            }
            ac[per[i].fid][cnt[per[i].fid]].good=per[i].fmx;
            ac[per[i].fid][cnt[per[i].fid]++].id=i;
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[0]-1>n/2){
            for(int i=n/2;i<cnt[0];i++){
                int wi=ac[0][i].id;
                ac[0][i].good=0;
                int wid=per[wi].sid,wmx=per[wi].smx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[0]=sizeof(ac[0]);
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[1]-1>n/2){
            for(int i=n/2;i<cnt[1];i++){
                int wi=ac[1][i].id;
                ac[1][i].good=0;
                int wid=per[wi].sid,wmx=per[wi].smx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[1]=sizeof(ac[1]);
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[2]-1>n/2){
            for(int i=n/2;i<cnt[2];i++){
                int wi=ac[2][i].id;
                ac[2][i].good=0;
                int wid=per[wi].sid,wmx=per[wi].smx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[2]=sizeof(ac[2]);
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[0]-1>n/2){
            for(int i=n/2;i<cnt[0];i++){
                int wi=ac[0][i].id;
                ac[0][i].good=0;
                int wid=per[wi].tid,wmx=per[wi].tmx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[0]=sizeof(ac[0]);
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[1]-1>n/2){
            for(int i=n/2;i<cnt[1];i++){
                int wi=ac[1][i].id;
                ac[1][i].good=0;
                int wid=per[wi].tid,wmx=per[wi].tmx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[1]=sizeof(ac[1]);
        }
        sort(ac[0],ac[0]+cnt[0],cmp);
        sort(ac[1],ac[1]+cnt[1],cmp);
        sort(ac[2],ac[2]+cnt[2],cmp);
        if(cnt[2]-1>n/2){
            for(int i=n/2;i<cnt[2];i++){
                int wi=ac[2][i].id;
                ac[2][i].good=0;
                int wid=per[wi].tid,wmx=per[wi].tmx;
                ac[wid][cnt[wid]].good=wmx;
                ac[wid][cnt[wid]++].id=wi;
            }
            cnt[2]=sizeof(ac[2]);
        }
        int ans=0;
        for(int i=0;i<cnt[0];i++){
            ans+=ac[0][i].good;
        }
        for(int i=0;i<cnt[1];i++){
            ans+=ac[1][i].good;
        }
        for(int i=0;i<cnt[2];i++){
            ans+=ac[2][i].good;
        }
        cout<<ans<<endl;
    }
    return 0;
}
