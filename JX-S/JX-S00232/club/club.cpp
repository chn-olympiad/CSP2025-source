#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
struct Node{
    int a,b,c;
    int mx,no,cha;
}a[N];
bool cmp(Node x,Node y){
    return x.mx>y.mx;
}
int ans;
int cnt[4];

priority_queue<PII>q1;
priority_queue<PII>q2;
priority_queue<PII>q3;
void add(int i,int no){
    int num;
    if(no==1){
        if(a[i].b>a[i].c){
            num=2;
        }else{
            num=3;
        }
        q1.push({a[i].cha,num});
    }else if(no==2){
        if(a[i].a>a[i].c){
            num=1;
        }else{
            num=3;
        }
        q2.push({a[i].cha,num});
    }else{
        if(a[i].b>a[i].a){
            num=2;
        }else{
            num=1;
        }
        q3.push({a[i].cha,num});
    }
}
void init(){
    while(!q1.empty()){
        q1.pop();
    }
    while(!q2.empty()){
        q2.pop();
    }
    while(!q3.empty()){
        q3.pop();
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        init();
        ans=0;
        cnt[1]=0;
        cnt[2]=0;
        cnt[3]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].mx=max(max(a[i].a,a[i].b),a[i].c);
            if(a[i].mx==a[i].a){
                a[i].no=1;
                a[i].cha=max(a[i].b,a[i].c)-a[i].mx;
            }else if(a[i].mx==a[i].b){
                a[i].no=2;
                a[i].cha=max(a[i].a,a[i].c)-a[i].mx;
            }else{
                a[i].no=3;
                a[i].cha=max(a[i].b,a[i].a)-a[i].mx;
            }
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            int no=a[i].no;
            if(cnt[no]<n/2){
                ans+=a[i].mx;
                cnt[no]++;
                add(i,no);
            }else{
                PII x;
                if(no==1){
                    x=q1.top();
                }else if(no==2){
                    x=q2.top();
                }else{
                    x=q3.top();
                }
                if(x.first>a[i].cha){
                    cnt[x.second]++;
                    ans+=a[i].mx+x.first;
                    if(no==1){
                        q1.pop();
                    }else if(no==2){
                        q2.pop();
                    }else{
                        q3.pop();
                    }
                    continue;
                }
                if(no==1){
                    if(a[i].b>a[i].c){
                        cnt[2]++;
                        ans+=a[i].b;
                    }else{
                        cnt[3]++;
                        ans+=a[i].c;
                    }
                }else if(no==2){
                    if(a[i].a>a[i].c){
                        cnt[1]++;
                        ans+=a[i].a;
                    }else{
                        cnt[3]++;
                        ans+=a[i].c;
                    }
                }else{
                    if(a[i].b>a[i].a){
                        cnt[2]++;
                        ans+=a[i].b;
                    }else{
                        cnt[1]++;
                        ans+=a[i].a;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
