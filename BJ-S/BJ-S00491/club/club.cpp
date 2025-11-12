#include<bits/stdc++.h>
using namespace std;
int t,n,b[3];
struct people{
    int h1,h2,h3,maxc;
}a[100005];
int findmax(int i){
    int maxnn=-1;
    if(a[i].h1>maxnn){
        maxnn=a[i].h1;
    }
    if(a[i].h2>maxnn){
        maxnn=a[i].h2;
    }
    if(a[i].h3>maxnn){
        maxnn=a[i].h3;
    }
    return maxnn;
}
int findmin(int i){
    int minnn=0x3f3f3f3f;
    if(a[i].h1<minnn){
        minnn=a[i].h1;
    }
    if(a[i].h2<minnn){
        minnn=a[i].h2;
    }
    if(a[i].h3<minnn){
        minnn=a[i].h3;
    }
    return minnn;
}
int findmaxpos(int i){
    int maxnn=-1,p=0;
    if(a[i].h1>maxnn){
        maxnn=a[i].h1;
        p=1;
    }
    if(a[i].h2>maxnn){
        maxnn=a[i].h2;
        p=2;
    }
    if(a[i].h3>maxnn){
        maxnn=a[i].h3;
        p=3;
    }
    return p;
}
int findsmaxpos(int i){
    int maxnn=-1,p=0;
    if(a[i].h1>maxnn){
        maxnn=a[i].h1;
        p=1;
    }
    if(a[i].h2>maxnn){
        maxnn=a[i].h2;
        p=2;
    }
    if(a[i].h3>maxnn){
        maxnn=a[i].h3;
        p=3;
    }
    //-------------------
    if(a[i].h1>maxnn&&a[i].h1!=maxnn){
        maxnn=a[i].h1;
        p=1;
    }
    if(a[i].h2>maxnn&&a[i].h2!=maxnn){
        maxnn=a[i].h2;
        p=2;
    }
    if(a[i].h3>maxnn&&a[i].h3!=maxnn){
        maxnn=a[i].h3;
        p=3;
    }
    return p;
}
int findsmax(int i){
    int maxnn=-1;
    if(a[i].h1>maxnn){
        maxnn=a[i].h1;
    }
    if(a[i].h2>maxnn){
        maxnn=a[i].h2;
    }
    if(a[i].h3>maxnn){
        maxnn=a[i].h3;
    }
    //-------------------
    if(a[i].h1>maxnn&&a[i].h1!=maxnn){
        maxnn=a[i].h1;
    }
    if(a[i].h2>maxnn&&a[i].h2!=maxnn){
        maxnn=a[i].h2;
    }
    if(a[i].h3>maxnn&&a[i].h3!=maxnn){
        maxnn=a[i].h3;
    }
    return maxnn;
}
bool cmp(people x,people y){
    return x.maxc>y.maxc;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        //memset(a,0,sizeof(a));
        b[0]=0;
        b[1]=0;
        b[2]=0;
        int maxp=n>>1;
        for(int i=0;i<n;i++){
            cin>>a[i].h1>>a[i].h2>>a[i].h3;
            a[i].maxc=findmax(i)-findmin(i);
            //cout<<a[i].maxc<<" ";
            //sort(a,a+n,cmp);
            if(b[findmaxpos(i)]<maxp){
                b[findmaxpos(i)]++;
                ans+=findmax(i);
            }else if(b[findsmaxpos(i)]<maxp){
                b[findsmaxpos(i)]++;
                ans+=findsmax(i);
            }else{
                ans+=findmin(i);
            }
        }

        cout<<ans<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
