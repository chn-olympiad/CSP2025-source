#include<bits/stdc++.h>
using namespace std;
int n,t;
    int p;
int maxx,maxk,maxa,maxb,maxc,sum,maxx2,maxk2,maxn;
long long f[3];
int a[100000][4];
void zuidazuobiao(int x1,int x2,int x3){
    if(max(max(x1,x2),x3)==x1){
            maxa=1;
    if(max(x2,x3)==x2){
        maxb=2;
        maxc=3;
    }else{
    maxb=3;
    maxc=2;
    }
    }else if(max(max(x1,x2),x3)==x2){
            maxa=2;
    if(max(x1,x3)==x1){
        maxb=1;
        maxc=3;
    }else{
    maxb=3;
    maxc=1;
    }

    }else if(max(max(x1,x2),x3)==x3){
            maxa=3;
    if(max(x2,x1)==x2){
        maxb=2;
        maxc=1;
    }else{
    maxb=1;
    maxc=2;
    }
}
}
void delta_max2(int n,int x,int y){
maxx2=0;
for(int i=1;i<=n;i++){
        int maxy=abs(a[i][x]-a[i][y]);
    if(maxy>maxx2){
        maxk2=i;
        maxx2=maxy;
    }
 }
 maxx2=max(a[maxk][x],a[maxk][y]);
 if(maxx2==a[maxk][x]){
    maxn=x;
 }else{
 maxn=y;
 }
}
void delta_max(int n){
maxx=0;
 for(int i=1;i<=n;i++){
        int maxy=max(max(abs(a[i][1]-a[i][2]),abs(a[i][2]-a[i][3])),abs(a[i][1]-a[i][3]));
    if(maxy>maxx){
        maxk=i;
        maxx=maxy;
    }
 }
}
void kick(int n,int l){
for(int i=l;i<=n;i++){
    if(i==n){
        a[i][1]=0;
        a[i][2]=0;
        a[i][3]=0;
    }else{
    a[i][1]=a[i+1][1];
    a[i][2]=a[i+1][2];
    a[i][3]=a[i+1][3];
    }
}
n--;
}
    int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
while(t>0){
        cin>>n;
        sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    int temp=n/2;
    p=n;
    for(int i=1;i<=p;i++){
        maxk=0;
        maxa=0;
        maxb=0;
        maxc=0;
        maxk2=0;
        maxn=0;
        delta_max(n);
        zuidazuobiao(a[maxk][1],a[maxk][2],a[maxk][3]);
        if(maxa==1){
            if(f[1]<temp){
                    sum+=a[maxk][maxa];
            f[1]++;
            kick(n,maxk);
            }else{
                if(f[2]<temp&&f[3]<temp){
            delta_max2(n,2,3);
            sum+=maxx2;
            f[maxn]++;
            kick(n,maxk2);
                }else if(f[2]<temp&&f[3]>=temp){
                sum+=a[maxk][2];
                f[2]++;
                kick(n,maxk);
                }else{
                sum+=a[maxk][3];
                f[3]++;
                kick(n,maxk);
                }

            }
        }else if(maxa==2){
            if(f[2]<temp){
                    sum+=a[maxk][maxa];
            f[2]++;
            kick(n,maxk);
            }else{
                if(f[1]<temp&&f[3]<temp){
            delta_max2(n,1,3);
            sum+=maxx2;
            f[maxn]++;
            kick(n,maxk2);
                }else if(f[1]<temp&&f[3]>=temp){
                sum+=a[maxk][1];
                f[1]++;
                kick(n,maxk);
                }else{
                sum+=a[maxk][1];
                f[1]++;
                kick(n,maxk);
                }

            }
        }else if(maxa==3){
            if(f[3]<temp){
                    sum+=a[maxk][maxa];
            f[3]++;
            kick(n,maxk);
            }else{
                if(f[2]<temp&&f[1]<temp){
            delta_max2(n,2,1);
            sum+=maxx2;
            f[maxn]++;
            kick(n,maxk2);
                }else if(f[2]<temp&&f[1]>=temp){
                sum+=a[maxk][2];
                f[2]++;
                kick(n,maxk);
                }else{
                sum+=a[maxk][1];
                f[1]++;
                kick(n,maxk);
                }

            }
        }

    }
    cout<<sum<<endl;
    t--;
    }
return 0;
}
