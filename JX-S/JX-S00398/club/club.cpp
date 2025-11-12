#include<bits/stdc++.h>
using namespace std;
struct club{
    int first,second,club;
} a[100005];
int maax(int a,int b,int c){
    return max(a,max(b,c));
}
int miin(int a,int b,int c){
    return min(a,min(b,c));
}
int mid(int a,int b,int c){
    return a+b+c-min(a,min(b,c))-max(a,max(b,c));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,x,y,z,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int ans=0;
        int club[4]={0};
        int s[100005]={0};
        for(int j=1;j<=n;j++){
            cin>>x>>y>>z;
            a[j].first=maax(x,y,z);
            a[j].second=mid(x,y,z);
            s[j]=a[j].first-a[j].second;
            if(a[j].first==x)a[j].club=1;
            if(a[j].first==y)a[j].club=2;
            if(a[j].first==z)a[j].club=3;
        }
        //sort(a.first+1,a.first+n+1,cmp);
        for(int j=1;j<=n;j++){
            ans+=a[j].first;
            club[a[j].club]++;
        }
        sort(s+1,s+n+1);
        if(club[1]>n/2){
            for(int j=1;j<=club[1]-(n/2);j++){
                ans-=s[j];
            }
        }else if(club[2]>n/2){
            for(int j=1;j<=club[2]-(n/2);j++){
                ans-=s[j];
            }
        }else if(club[3]>n/2){
            for(int j=1;j<=club[3]-(n/2);j++){
                ans-=s[j];
            }
        }
        //cout<<club[1]<<' ' <<club[2]<<' ' <<club[3]<<endl;
        /*for(int j=1;j<=n;j++){
            cout<<s[j]<<' ';
        }
        cout<<endl;*/
        cout<<ans<<endl;
    }
    return 0;
}
