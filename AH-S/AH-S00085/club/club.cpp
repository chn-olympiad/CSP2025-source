#include<bits/stdc++.h>
using namespace std;
struct p{
    int a,b,c,l,x,y,z;
};
bool cmp1(p u,p v){
    return u.x>v.x;
}
int t,n,s1,s2,s3,s;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--){
        p m[10005];
        s1=0;
        s2=0;
        s3=0;
        s=0;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>m[i].a>>m[i].b>>m[i].c;
            if (m[i].a>=m[i].b&&m[i].a>=m[i].c){
                m[i].x=m[i].a;m[i].l=1;
                s1++;
                if (m[i].b>=m[i].c) m[i].y=m[i].b;
                else m[i].y=m[i].c;
                m[i].z=m[i].x-m[i].y;
            }
            else if (m[i].b>=m[i].a&&m[i].b>=m[i].c){
                m[i].x=m[i].b;m[i].l=2;
                s2++;
                if (m[i].a>=m[i].c) m[i].y=m[i].a;
                else m[i].y=m[i].c;
                m[i].z=m[i].x-m[i].y;
            }
            else if (m[i].c>=m[i].a&&m[i].c>=m[i].b){
                m[i].x=m[i].c;m[i].l=3;
                s3++;
                if (m[i].a>=m[i].b) m[i].y=m[i].a;
                else m[i].y=m[i].b;
                m[i].z=m[i].x-m[i].y;
            }
        }
        sort(m+1,m+n+1,cmp1);
        if (s1>(n/2)){
			s1=n/2;
            for (int i=1;i<=n;i++){
                if (s1==0&&m[i].l==1) m[i].x=m[i].y;
                else if (m[i].l==1) s1--;
            }
        }
        else if (s2>(n/2)){
			s2=n/2;
            for (int i=1;i<=n;i++){
                if (s2==0&&m[i].l==2) m[i].x=m[i].y;
                else if (m[i].l==2) s2--;
            }
        }
        else if (s3>(n/2)){
			s3=n/2;
            for (int i=1;i<=n;i++){
                if (s3==0&&m[i].l==3) m[i].x=m[i].y;
                else if (m[i].l==3) s3--;
            }
        }
        for (int i=1;i<=n;i++) s+=m[i].x;
        cout<<s<<endl;
    }

    return 0;
}
