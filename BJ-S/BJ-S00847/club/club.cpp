#include<bits/stdc++.h>
using namespace std;

long long b[100500],c[100500];
long long bp[100500],d[100500],bel[100500];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

    long long t;
    cin>>t;
    while(t--){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(bp,0,sizeof(bp));
		memset(bel,0,sizeof(bel));
		memset(d,0,sizeof(d));
        long long n,m=0,ans=0,cnt=0,cha=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            //cin>>a[i][1]>>a[i][2]>>a[i][3];
            int x,y,z,mx,mxp,mn;
            cin>>x>>y>>z;
            if(x>=y&&x>=z){mx=x;mxp=1;}
            if(y>=x&&y>=z){mx=y;mxp=2;}
            if(z>=x&&z>=y){mx=z;mxp=3;}
            if(mxp==1)x=0;
            if(mxp==2)y=0;
            if(mxp==3)z=0;
            if(x>=y&&x>=z){mn=x;}
            if(y>=x&&y>=z){mn=y;}
            if(z>=x&&z>=y){mn=z;}
            b[i]=mx;bp[i]=mxp;
            c[i]=mx-mn;
            bel[mxp]++;
            ans+=mx;
            //cout<<mx<<" "<<mn<<endl;
        }
        //for (int i=1;i<=3;i++)cout<<bel[i]<<" ";
        //cout<<endl;
        for (int i=1;i<=3;i++){
			if(bel[i]>n/2){m=i;cha=bel[i]-(n/2);}
        }
        if(m!=0){
			for (int i=1;i<=n;i++){
				if(bp[i]==m){
					d[++cnt]=c[i];
				}
			}
			sort(d+1,d+cnt+1);
			for (int i=1;i<=cha;i++){
				ans-=d[i];
			}
        }
        cout<<ans<<endl;
    }
    
    return 0;
}