#include<bits/stdc++.h>
using namespace std;
struct s{
    int x1,x2,x3;
}a[100005];
struct st{
    int ss1,ss2;
};
bool cmp(st st1,st st2){
    return st1.ss1>st2.ss1;
}
int t,n,aa1,aa2,aa3;
long long ans;
priority_queue<pair<int,int> > q1;
priority_queue<pair<int,int> > q2;
priority_queue<pair<int,int> > q3;
st a1[100005];
st a2[100005];
st a3[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].x1>>a[i].x2>>a[i].x3;
        }
        aa1=0;
        aa2=0;
        aa3=0;
        ans=0;
        //sort(a,a+n,cmp1);
        for(int i=0;i<n;i++){
            /*if(a[i].x1>a[i].x2&&a[i].x1>a[i].x3){
                int x=a[i].x1-max(a[i].x2,a[i].x3);
                int y=a[i].x1;
                q1.push( pair<'2',4> );

                ans+=a[i].x1;
                if(q1.size()>(n/2)){
                    ans-=q1.top().second;
                    q1.pop();
                }
            }
            else if(a[i].x2>a[i].x1&&a[i].x2>a[i].x3){
                q2.push(pair<a[i].x2-max(a[i].x1,a[i].x3),a[i].x2>);
                ans+=a[i].x2;
                if(q2.size()>(n/2)){
                    ans-=q2.top().second;
                    q2.pop();
                }
            }
            else{
                q3.push(pair<a[i].x3-max(a[i].x1,a[i].x2),a[i].x2>);
                ans+=a[i].s3;
                if(q3.size()>(n/2)){
                    ans-=q3.top().second;
                    q3.pop();
                }
            }
        }
        cout<<ans;*/

            if(a[i].x1>a[i].x2&&a[i].x1>a[i].x3){
                int x=a[i].x1-max(a[i].x2,a[i].x3);
                int y=a[i].x1;
                a1[++aa1].ss1=x;
                a1[aa1].ss2=y;

                ans+=a[i].x1;
                if(aa1>(n/2)){
                    sort(a1+1,a1+aa1+1,cmp);
                    ans-=a1[aa1].ss1;
                    aa1--;
                }
            }
            else if(a[i].x2>a[i].x1&&a[i].x2>a[i].x3){
                int x=a[i].x2-max(a[i].x1,a[i].x3);
                int y=a[i].x2;
                a2[++aa2].ss1=x;
                a2[aa2].ss2=y;

                ans+=a[i].x2;
                if(aa2>(n/2)){
                    //cout<<"6660;";
                    sort(a2+1,a2+aa2+1,cmp);
                    ans-=a2[aa2].ss1;
                    aa2--;
                }
            }
            else{
                int x=a[i].x3-max(a[i].x1,a[i].x2);
                int y=a[i].x3;
                a3[++aa3].ss1=x;
                a3[aa3].ss2=y;

                ans+=a[i].x3;
                if(aa3>(n/2)){
                    sort(a3+1,a3+aa3+1,cmp);
                    ans-=a3[aa3--].ss1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
