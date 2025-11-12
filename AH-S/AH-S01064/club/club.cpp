#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
    int x,y,z;
    int idx;
}s[100005];
int cnt,cnt1,cnt2;
bool cmp(stu a,stu b){
    if(a.idx!=b.idx){
        return a.idx<b.idx;
    }
    if(a.x!=b.x){
        return a.x>b.x;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cnt=0;
        cnt1=0;
        cnt2=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].x>>s[i].y>>s[i].z;
            if(s[i].x>=s[i].y&&s[i].x>=s[i].z){
                s[i].idx=1;
                cnt++;
            }
            else if(s[i].y>=s[i].x&&s[i].y>=s[i].z){
                s[i].idx=2;
                cnt1++;
            }
            else {
                s[i].idx=3;
                cnt2++;
            }
        }
        sort(s+1,s+n+1,cmp);
        if(cnt<=n/2&&cnt1<=n/2&&cnt2<=n/2){
            long long sum=0;
            for(int i=1;i<=n;i++){
                sum+=max(s[i].x,max(s[i].y,s[i].z));
            }
            cout<<sum<<endl;
        }
        else{
            long long sum=0;
            int cnta=0,cntb=0,cntc=0;
            for(int i=n;i>=1;i--){
                if(s[i].idx==1){
                    if(cnta+1<=n/2){
                        sum+=s[i].x;
                        cnta++;
                    }
                    else{
                        if(s[i].y>s[i].z&&cnt1+1<=n/2){
                            sum+=s[i].y;
                            s[i].idx=2;
                        }
                        else if(cnt2+1<=n/2){
                            sum+=s[i].z;
                            s[i].idx=3;
                        }
                    }
                }
            }
            for(int i=n;i>=1;i--){
                if(s[i].idx==2){
                    if(cntb+1<=n/2){
                        sum+=s[i].y;
                        cntb++;
                    }
                    else{
                        if(s[i].x>s[i].z&&cnt+1<=n/2){
                            sum+=s[i].x;
                            s[i].idx=1;
                        }
                        else if(cnt2+1<=n/2){
                            sum+=s[i].z;
                            s[i].idx=3;
                        }
                    }
                }
            }
            for(int i=n;i>=1;i--){
                if(s[i].idx==3){
                    if(cntc+1<=n/2){
                        sum+=s[i].z;
                        cntc++;
                    }
                    else{
                        if(s[i].x>s[i].y&&cnt+1<=n/2){
                            sum+=s[i].x;
                            s[i].idx=1;
                        }
                        else if(cnt1+1<=n/2){
                            sum+=s[i].y;
                            s[i].idx=2;
                        }
                    }
                }
            }
        cout<<sum<<endl;
        }
    }
    return 0;
}
