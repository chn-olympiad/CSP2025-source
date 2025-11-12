#include<bits/stdc++.h>
using namespace std;

int t,n,peo[3][100005],ans;
struct op
{
    int fi,se,th,v1,v2,v3;
}l1[100005],l2[100005],l3[100005];
int ren[4];

bool cmp(op a,op b)
{
    if(a.fi!=b.fi) return a.fi<b.fi;
    else if(a.se != b.se) return a.se>b.se;
    else return a.th>b.th;
}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=3;i++) ren[i]=0;ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d%d",&peo[1][i],&peo[2][i],&peo[3][i]);
        for(int i=1;i<=n;i++)
        {
            op a={peo[1][i],1},b={peo[2][i],2},c={peo[3][i],3};
            if(c.fi>a.fi) swap(a,c); if(b.fi<c.fi) swap(b,c); if(a.fi<b.fi) swap(a,b);
            if(ren[a.se]+1<=n/2) // if the man can enter the club which he love first
            {
                if     (a.se==1) l1[++ren[1]]={a.fi,b.fi,c.fi,a.se,b.se,c.se};
                else if(a.se==2) l2[++ren[2]]={a.fi,b.fi,c.fi,a.se,b.se,c.se};
                else             l3[++ren[3]]={a.fi,b.fi,c.fi,a.se,b.se,c.se};
                ans+=a.fi;
            }
            else // the number of member is too big
            {
                if(a.se==1)
                {
                    sort(l1+1,l1+ren[1]+1,cmp);
                    int s1=l1[1].fi,s2=l1[1].se,s3=l1[1].th,id1=l1[1].v1,id2=l1[1].v2,id3=l1[1].v3;
                    if(1==id1)// if it is changed not yet
                        if(ans-s1+s2+a.fi > ans+b.fi) {ans=ans-s1+s2+a.fi; if(id2==2)l2[++ren[2] ]=l1[1];else l3[++ren[3] ]=l1[1]; l1[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                        else {ans+=b.fi; if(b.se==2) l2[++ren[2] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l3[++ren[3] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                    else // it has done changed already
                        if(ans-s2+s3+a.fi > ans+b.fi){ans=ans-s2+s3+a.fi;  if(id3==2)l2[++ren[2] ]=l1[1];else l3[++ren[3] ]=l1[1]; l1[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se};}
                        else {ans+=b.fi; if(b.se==2) l2[++ren[2] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l3[++ren[3] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                }
                else if(a.se==2)
                {
                    sort(l2+1,l2+ren[2]+1,cmp);
                    int s1=l2[1].fi,s2=l2[1].se,s3=l2[1].th,id1=l2[1].v1,id2=l2[1].v2,id3=l2[1].v3;
                    if(2==id1)// if it is changed not yet
                        if(ans-s1+s2+a.fi > ans+b.fi) {ans=ans-s1+s2+a.fi; if(id2==1)l1[++ren[1] ]=l2[1];else l3[++ren[3] ]=l2[1]; l2[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                        else {ans+=b.fi; if(b.se==1) l1[++ren[1] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l3[++ren[3] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                    else // it has done changed already
                        if(ans-s2+s3+a.fi > ans+b.fi){ans=ans-s2+s3+a.fi;  if(id3==1)l1[++ren[1] ]=l2[1];else l3[++ren[3] ]=l2[1]; l2[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se};}
                        else {ans+=b.fi; if(b.se==1) l1[++ren[1] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l3[++ren[3] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                }
                else
                {
                    sort(l3+1,l3+ren[3]+1,cmp);
                    int s1=l3[1].fi,s2=l3[1].se,s3=l3[1].th,id1=l3[1].v1,id2=l3[1].v2,id3=l3[1].v3;
                    if(3==id1)// if it is changed not yet
                        if(ans-s1+s2+a.fi > ans+b.fi) {ans=ans-s1+s2+a.fi; if(id2==2)l2[++ren[2] ]=l3[1];else l1[++ren[1] ]=l3[1]; l3[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                        else {ans+=b.fi; if(b.se==2) l2[++ren[2] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l1[++ren[1] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                    else // it has done changed already
                        if(ans-s2+s3+a.fi > ans+b.fi){ans=ans-s2+s3+a.fi;  if(id3==2)l2[++ren[2] ]=l1[1];else l1[++ren[1] ]=l3[1]; l3[1]={a.fi,b.fi,c.fi,a.se,b.se,c.se};}
                        else {ans+=b.fi; if(b.se==2) l2[++ren[2] ]={a.fi,b.fi,c.fi,a.se,b.se,c.se}; else l1[++ren[1] ]= {a.fi,b.fi,c.fi,a.se,b.se,c.se}; }
                }
            }

        }
        cout<<ans<<"\n";//cout<<"\n";
    }
    return 0;
}
/*147325
125440
152929
150176
158541*/
