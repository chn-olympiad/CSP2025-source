#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct e{
    int z,h,r;
}a[3000004];
bool vis[1000006];

int an[4];

int check(){
    int sum=0;
    int j=0;
    //for(int i=1;i<=3*n;i++){
    //    for(int j=1;j<=3*n;j++)
    //}

    for(int i=1;i<=3*n;i++){
        if(j==n){

            //cout<<"break  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
            break;
        }
        if(an[a[i].h]>=n/2){
        //cout<<"continue1  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        continue;
            }
        if(vis[a[i].r]==true){
            //cout<<"continue2  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        continue;
        }
        sum+=a[i].z;
        //cout<<sum<<endl;
        vis[a[i].r]=true;
        an[a[i].h]++;
        j++;

        //cout<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        /*
        int maxa=0,maxi=0;
        for(int j=1;j<=3;j++){
            if(an[j]>n/2) continue ;
             if(a[j][i]>maxa){
                maxa=a[j][i]
                maxi=j;
             }

        }
        */
    }
        memset(an,0,sizeof(an));
        for(int i=1;i<=n;i++){
            vis[i]=0;
        }
    return sum;

}

int check2(){
    int sum=0;
    int j=0;
    //for(int i=1;i<=3*n;i++){
    //    for(int j=1;j<=3*n;j++)
    //}

    for(int i=2;i<=3*n;i++){
        if(j==n){

            //cout<<"break  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
            break;
        }
        if(an[a[i].h]>=n/2){
        //cout<<"continue1  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        continue;
            }
        if(vis[a[i].r]==true){
            //cout<<"continue2  "<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        continue;
        }
        sum+=a[i].z;
        //cout<<sum<<endl;
        vis[a[i].r]=true;
        an[a[i].h]++;
        j++;

        //cout<<a[i].z<<" "<<a[i].h<<" "<<a[i].r<<endl;
        /*
        int maxa=0,maxi=0;
        for(int j=1;j<=3;j++){
            if(an[j]>n/2) continue ;
             if(a[j][i]>maxa){
                maxa=a[j][i]
                maxi=j;
             }

        }
        */
    }
    return sum;
}

bool cmp(e a,e b){
    return a.z>b.z;
}

int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
            ans=0;
            int last=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[++last].z>>a[++last].z>>a[++last].z;

            a[last-2].h=1;
            a[last-1].h=2;
            a[last].h=3;
            a[last-2].r=j;
            a[last-1].r=j;
            a[last].r=j;
            //cout<<a[last-2].z<<" "<<a[last-2].r<<endl;
            //cout<<a[last-1].z<<" "<<a[last-1].r<<endl;
            //cout<<a[last].z<<" "<<a[last].r<<endl;
        }
        //cout<<a[1].r<<endl;
        sort(a+1,a+last+1,cmp);
        //cout<<a[1].r<<endl;

        //for(int j=1;j<=last;j++){
        //    cout<<a[j].z<<" "<<a[j].h<<" "<<a[j].r<<endl;

        //}
/*
        int l=1,r=20000;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)==true){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
*/
        int ans18=check();
        ans18=max(ans18,check2());
        cout<<ans18<<endl;
        for(int j=1;j<=last;j++){
            a[j].z=0;
            a[j].h=0;
            a[j].r=0;
            vis[j]=false;
        }
        memset(an,0,sizeof(an));
    }

    return 0;
}
