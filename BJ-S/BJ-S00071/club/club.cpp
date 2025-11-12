#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a,b,c;
    int man,mix,mid;
}az[100001];
int t,n;
bool cmp(int x,int y){
    node a=az[x],b=az[y];
    if(a.man-a.mid!=b.man-b.mid){
        return a.man-a.mid>b.man-b.mid;
    }
    return a.man-a.mix>b.man-b.mix;
}

int b[1000001],c[1000001],d[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;++i){
            cin>>az[i].a>>az[i].b>>az[i].c;
            az[i].man=max( max(az[i].a,az[i].b) , az[i].c);
            az[i].mix=min( min(az[i].a,az[i].b) , az[i].c);
            az[i].mid=az[i].a+az[i].b+az[i].c-az[i].man-az[i].mix;
            //cout<<az[i].man<<' '<<az[i].mid<<' '<<az[i].mix<<endl;
        }
        int tota=0,totb=0,totc=0,ans=0;;
        for(int i=1;i<=n;i++){
            if(az[i].man==az[i].a){
                b[++tota]=i;
            }
            if(az[i].man==az[i].b){
                c[++totb]=i;
            }
            if(az[i].man==az[i].c){
                d[++totc]=i;
            }
            ans+=az[i].man;
        }
        //cout<<ans<<endl;
        sort(b+1,b+tota+1,cmp);
        sort(c+1,c+totb+1,cmp);
        sort(d+1,d+totc+1,cmp);
        //for(int i=1;i<=tota;i++){
		//	cout<<b[i]<<' ';
		//}cout<<endl;
        if(tota>n/2){
            for(int i=tota;i>n/2;i--){
                int x=b[i];
                //cout<<x<<endl;
                ans-=az[x].man-az[x].mid;
            }
        }
        else if(totb>n/2){
            for(int i=totb;i>n/2;i--){
                int x=c[i];
                ans-=az[x].man-az[x].mid;
            }
        }
        else if(totc>n/2){
            for(int i=totc;i>n/2;i--){
                int x=d[i];
                ans-=az[x].man-az[x].mid;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
