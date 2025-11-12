#include<bits/stdc++.h>
using namespace std;
int _,n,clubed[3],unclubed,unclubedclub;long long ans;
struct club{
    int score,club;
};struct node{
    club a[3];
}a[1000000];
bool cmp1(club x,club y){
    return x.score>y.score;
}bool cmp2(node x,node y){
    if(x.a[0].club!=unclubedclub)return 0;
    return 1;
}bool cmp3(node x,node y){
    return x.a[0].score-x.a[1].score<y.a[0].score-y.a[1].score;
}int main(){
    freopen("club.in","r",stdin);freopen("club.out","w",stdout);
    cin>>_;
    while(_--){
        clubed[0]=clubed[1]=clubed[2]=unclubed=0;ans=0ll;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i].a[j].score;a[i].a[j].club=j;
            }
        }for(int i=0;i<n;i++)sort(a[i].a,a[i].a+3,cmp1);
        for(int i=0;i<n;i++)clubed[a[i].a[0].club]++;
        for(int i=0;i<3;i++){
            if(clubed[i]>n/2){
                unclubedclub=i;unclubed=clubed[i]-n/2;
            }
        }sort(a,a+n,cmp2);sort(a,a+clubed[unclubedclub],cmp3);
        for(int i=0;i<unclubed;i++){
            a[i].a[0].score=a[i].a[1].score;
        }for(int i=0;i<n;i++){
            ans+=a[i].a[0].score;
        }cout<<ans<<endl;
    }return 0;
}