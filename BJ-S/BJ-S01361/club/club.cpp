#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;

struct node{
    int a,b,c;
    int max_num,second_num,min_num;
    int chazhi;
};
node student[100005];

bool cmp(node x,node y){
    return x.chazhi>y.chazhi;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0,cnt[4]={0,0,0,0};
        for(int i=0;i<n;i++){
            cin>>student[i].a>>student[i].b>>student[i].c;
            student[i].max_num=max(student[i].a,max(student[i].b,student[i].c));
            student[i].min_num=min(student[i].a,min(student[i].b,student[i].c));
            student[i].second_num=student[i].a+student[i].b+student[i].c-student[i].max_num-student[i].min_num;
            student[i].chazhi=student[i].second_num-student[i].max_num;
            if(student[i].a>=student[i].b&&student[i].a>=student[i].c) cnt[1]++;
            else if(student[i].b>=student[i].a&&student[i].b>=student[i].c) cnt[2]++;
            else cnt[3]++;
            ans+=student[i].max_num;
        }
        sort(student,student+n,cmp);
        int i=0;
        while(cnt[1]>n/2){
            //cout<<"!"<<endl;
            if(student[i].max_num!=student[i].a) {
                i++;
                continue;
            }
            ans+=student[i].chazhi;
            i++,cnt[1]--;
        }
        i=0;
        while(cnt[2]>n/2){
            //cout<<"!!"<<endl;
            if(student[i].max_num!=student[i].b) {
                i++;
                continue;
            }
            ans+=student[i].chazhi;
            i++,cnt[2]--;
        }
        i=0;
        while(cnt[3]>n/2){
            //cout<<student[i].max_num<<" "<<student[i].c<<endl;
            if(student[i].max_num!=student[i].c){
                i++;
                continue;
            }
            ans+=student[i].chazhi;
            i++,cnt[3]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
