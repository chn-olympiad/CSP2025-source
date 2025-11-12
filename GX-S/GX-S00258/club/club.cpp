#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct Cl{
    int a,b,c;
}v[N];
int f[4];
bool cmp(Cl k,Cl l)
{
    int maxk=max(max(k.a,k.b),k.c),maxl=max(max(l.a,l.b),l.c);
    return maxk>maxl;
}
bool cmp1(Cl k,Cl l)
{
    int maxk=0,maxl=0;
    if(k.a==0) maxk++;
    if(k.b==0) maxk++;
    if(k.c==0) maxk++;
    if(l.a==0) maxl++;
    if(l.b==0) maxl++;
    if(l.c==0) maxl++;
    return maxk>maxl&&maxk!=3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t,n,sum=0,m;
    cin >> t;
    while(t--){
        sum=0;
        f[1]=0;f[2]=0;f[3]=0;
        cin >> n;
        m=n/2;
        for(int i=0;i<n;i++) cin >> v[i].a >> v[i].b >> v[i].c;
        sort(v,v+n,cmp);
        sort(v,v+n,cmp1);
        for(int i=0;i<n;i++){
            if(max(max(v[i].a,v[i].b),v[i].c)==v[i].a){
                if(f[1]+1>m){
                    if(max(v[i].b,v[i].c)==v[i].b){
                        if(f[2]+1<=m){
                            sum+=v[i].b;
                            f[2]++;
                            continue;
                        }
                    }
                    sum+=v[i].c;
                    f[3]++;
                }
                else{
                    sum+=v[i].a;
                    f[1]++;
                }
            }
            else if(max(max(v[i].a,v[i].b),v[i].c)==v[i].b){
                if(f[2]+1>m){
                    if(max(v[i].a,v[i].c)==v[i].a){
                        if(f[1]+1<=m){
                            sum+=v[i].a;
                            f[1]++;
                            continue;
                        }
                    }
                    sum+=v[i].c;
                    f[3]++;
                }
                else{
                    sum+=v[i].b;
                    f[2]++;
                }
            }
            else{
                if(f[3]+1>m){
                    if(max(v[i].a,v[i].b)==v[i].a){
                        if(f[1]+1<=m){
                            sum+=v[i].a;
                            f[1]++;
                            continue;
                        }
                    }
                    sum+=v[i].b;
                    f[2]++;
                }
                else{
                    sum+=v[i].c;
                    f[3]++;
                }
            }
        }
        cout << sum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
