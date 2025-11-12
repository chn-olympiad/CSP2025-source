#include <bits/stdc++.h>
using namespace std;

struct person{
    int a,b,c,max_n,ind,mid_n,ind2,min_n,ind3,flag=0;
}p[100001];

int max_i(int,int,int);
int min_i(int,int,int);
int mid_i(int,int,int,int);
bool cmp(person,person);
bool cmp2(person,person);
bool cmp3(person,person);

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,a,b,c,cnt;
        long long sum=0;
        cin>>n;
        a=b=c=n/2;
        for(int j=1;j<=n;j++){
            cin>>p[j].a>>p[j].b>>p[j].c;
            p[j].max_n=max(max(p[j].a,p[j].b),p[j].c);
            p[j].min_n=min(min(p[j].a,p[j].b),p[j].c);
            p[j].ind=max_i(p[j].a,p[j].b,p[j].c);
            p[j].ind3=min_i(p[j].a,p[j].b,p[j].c);
            p[j].ind2=6-p[j].ind-p[j].ind3;
            p[j].mid_n=mid_i(p[j].a,p[j].b,p[j].c,p[j].ind2);
        }
        sort(p+1,p+n+1,cmp);
        for(int j=1;j<=n;j++){

        }
        cnt=n;
        for(int j=1;j<=n;j++){
            if(p[j].ind==1 && a!=0){
                sum+=p[j].max_n;
                p[j].flag=1;
                a--;
                cnt--;
            }if(p[j].ind==2 && b!=0){
                sum+=p[j].max_n;
                p[j].flag=1;
                b--;
                cnt--;
            }if(p[j].ind==3 && c!=0){
                sum+=p[j].max_n;
                p[j].flag=1;
                c--;
                cnt--;
            }
        }if(cnt==0){
            cout<<sum<<endl;
            continue;
        }
        sort(p+1,p+n+1,cmp2);
        for(int j=1;j<=n,p[j].flag==0;j++){
            if(p[j].ind2==1 && a!=0){
                sum+=p[j].mid_n;
                p[j].flag=1;
                a--;
                cnt--;
            }if(p[j].ind2==2 && b!=0){
                sum+=p[j].mid_n;
                p[j].flag=1;
                b--;
                cnt--;
            }if(p[j].ind2==3 && c!=0){
                sum+=p[j].mid_n;
                p[j].flag=1;
                c--;
                cnt--;
            }
        }if(cnt==0){
            cout<<sum<<endl;
            continue;
        }
        sort(p+1,p+n+1,cmp3);
        for(int j=1;j<=n,p[j].flag==0;j++){
            if(p[j].ind3==1 && a!=0){
                sum+=p[j].min_n;
                p[j].flag=1;
                a--;
                cnt--;
            }if(p[j].ind3==2 && b!=0){
                sum+=p[j].min_n;
                p[j].flag=1;
                b--;
                cnt--;
            }if(p[j].ind3==3 && c!=0){
                sum+=p[j].min_n;
                p[j].flag=1;
                c--;
                cnt--;
            }
        }cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

int max_i(int a,int b,int c){
    int maxx=max(max(a,b),c);
    if(maxx==a) return 1;
    if(maxx==b) return 2;
    return 3;
}

int min_i(int a,int b,int c){
    int minn=min(min(a,b),c);
    if(minn==a) return 1;
    if(minn==b) return 2;
    return 3;
}

int mid_i(int a,int b,int c,int m){
    if(m==1) return a;
    if(m==2) return b;
    return c;
}

bool cmp(person a,person b){
    return a.max_n>b.max_n;
}

bool cmp2(person a,person b){
    return a.mid_n>b.mid_n;
}

bool cmp3(person a,person b){
    return a.min_n>b.min_n;
}

