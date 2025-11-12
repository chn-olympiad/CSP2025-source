#include<bits/stdc++.h>
using namespace std;
int N;
int n,d[100005],a1[100005][5],b1[100005][5],c1[100005][5],aa=1,bb=1,cc=1,ans=0;
void pp(int r){
    r=n;
    int o=1,u=0;
    while(o<aa){
        if(a1[o][1]<a1[o+1][1]){
            int q=a1[o][1],w=a1[o][2],e=a1[o][3];
            a1[o][1]=a1[o+1][1];
            a1[o][2]=a1[o+1][2];
            a1[o][3]=a1[o+1][3];
            a1[o+1][1]=q;
            a1[o+1][2]=w;
            a1[o+1][3]=e;
            u++;
        }
        o++;
        if(o==aa-1){
            if(u!=0){
                u=0;
                o=1;
            }
        }
    }
    o=1;
    while(o<bb){
        if(b1[o][2]<b1[o+1][2]){
            int q=b1[o][1],w=b1[o][2],e=b1[o][3];
            b1[o][1]=b1[o+1][1];
            b1[o][2]=b1[o+1][2];
            b1[o][3]=b1[o+1][3];
            b1[o+1][1]=q;
            b1[o+1][2]=w;
            b1[o+1][3]=e;
            u++;
        }
        o++;
        if(o==bb-1){
            if(u!=0){
                u=0;
                o=1;
            }
        }
    }
    o=1;
    while(o<cc){
        if(c1[o][3]<c1[o+1][3]){
            int q=c1[o][1],w=c1[o][2],e=c1[o][3];
            c1[o][1]=c1[o+1][1];
            c1[o][2]=c1[o+1][2];
            c1[o][3]=c1[o+1][3];
            c1[o+1][1]=q;
            c1[o+1][2]=w;
            c1[o+1][3]=e;
            u++;
        }
        o++;
        if(o==aa-1){
            if(u!=0){
                u=0;
                o=1;
            }
        }
    }
}
void apai(int x,int y){
    for(int i=x;i<=y;i++){
    int k=max(a1[i][2],a1[i][3]);
    if(k==a1[i][2]){
        b1[bb][1]=a1[i][1];
        b1[bb][2]=a1[i][2];
        b1[bb][3]=a1[i][3];
        bb++;
    }
    else if(k==a1[i][3]){
        c1[cc][1]=a1[i][1];
        c1[cc][2]=a1[i][2];
        c1[cc][3]=a1[i][3];
        cc++;
    }
}
aa=n/2;
}
void bpai(int x,int y){
    for(int i=x;i<=y;i++){
    int k=max(b1[i][1],b1[i][3]);
    if(k==b1[i][1]){
        a1[aa][1]=b1[i][1];
        a1[aa][2]=b1[i][2];
        a1[aa][3]=b1[i][3];
        aa++;
    }
    else if(k==b1[i][3]){
        c1[cc][1]=b1[i][1];
        c1[cc][2]=b1[i][2];
        c1[cc][3]=b1[i][3];
        cc++;
    }
}
bb=n/2;
}
void cpai(int x,int y){
    for(int i=x;i<=y;i++){
    int k=max(c1[i][1],c1[i][2]);
    if(k==c1[i][1]){
        b1[bb][1]=c1[i][1];
        b1[bb][2]=c1[i][2];
        b1[bb][3]=c1[i][3];
        bb++;
    }
    else if(k==c1[i][2]){
        a1[aa][1]=c1[i][1];
        a1[aa][2]=c1[i][2];
        a1[aa][3]=c1[i][3];
        aa++;
    }
}
cc=n/2;
}
int main(int oo){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>N;
for(int pop=1;pop<=N;pop++){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,k;
        cin>>a>>b>>c;
        k=max(a,b);
        k=max(k,c);
        if(k==a){
            a1[aa][1]=a;
            a1[aa][2]=b;
            a1[aa][3]=c;
            aa++;
        }
        if(k==b){
            b1[bb][1]=a;
            b1[bb][2]=b;
            b1[bb][3]=c;
            bb++;
        }
        if(k==c){
            c1[cc][1]=a;
            c1[cc][2]=b;
            c1[cc][3]=c;
            cc++;
        }
    }
    pp(1);
    if(aa>n/2)apai(n/2+1,aa-1);
    else if(bb>n/2)bpai(n/2+1,bb-1);
    else if(cc>n/2)cpai(n/2+1,cc-1);
    for(int i=1;i<=aa;i++){
        ans+=a1[i][1];
        //cout<<a1[i][1]<<endl;
    }
    for(int i=1;i<=bb;i++){
        ans+=b1[i][2];
    }
    for(int i=1;i<=cc;i++){
        ans+=c1[i][3];
        //cout<<c1[i][3]<<endl;
    }
        cout<<ans<<endl;
        n=0;
        bb=0;
        cc=0;
        aa=0;
        ans=0;
        //cout<<b1[1][2]<<" "<<b1[2][2]<<" "<<b1[3][2]<<endl;
}
return 0;
}
