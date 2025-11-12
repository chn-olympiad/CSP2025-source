#include<bits/stdc++.h>
using namespace std;

const int N= 1e5 + 9;
int t,n;
struct node{
    int a,b,c,mx,ma,mn,id;
}a[N];

bool f1=true;
bool f2=true;

bool cmp(node a,node b){
    if(a.mx==b.mx){
        if(a.ma==b.ma){
            if(a.mn==b.mn){
                return a.id<b.id;
            }
            return a.mn>b.mn;
        }
        return a.ma>b.ma;
    }
    return a.mx>b.mx;
}

void Main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        a[i].id=i;
        cin>>a[i].a>>a[i].b>>a[i].c;
        if(a[i].b!=0||a[i].c!=0){
            f1=false;
        }
        if(a[i].c!=0){
            f2=false;
        }
        a[i].mx=max(a[i].a,max(a[i].b,a[i].c));
        a[i].mn=min(a[i].a,max(a[i].b,a[i].c));
        if(a[i].a==a[i].mx){
            a[i].ma=max(a[i].b,a[i].c);
        }
        if(a[i].b==a[i].mx){
            a[i].ma=max(a[i].a,a[i].c);
        }
        if(a[i].c==a[i].mx){
            a[i].ma=max(a[i].a,a[i].b);
        }
    }
    int x=0,y=0,z=0;
    long long ans=0;
    sort(a+1,a+n+1,cmp);
    if(f1){
        for(int i=1;i<=n/2;++i){
            ans+=a[i].a;
        }
        cout<<ans<<endl;

    }
    else if(f2){
        for(int i=1;i<=n;++i){
            if(a[i].a>a[i].b&&x<n/2){
                x++;
                ans+=a[i].a;
            }
            else if(a[i].b>a[i].a&&y<n/2){
                y++;
                ans+=a[i].b;
            }
            else{
                if(x<=y){
                    ++x;
                    ans+=a[i].a;
                }
                else if(y<x){
                    ++y;
                    ans+=a[i].b;
                }
            }
        }
        cout<<ans<<endl;
    }
    else{
        for(int i=1;i<=n;++i){
            if(a[i].a==a[i].mx){
                if(x<n/2){
                    ans+=a[i].a;
                    ++x;
                }
                else if(a[i].b==a[i].ma){
                    if(y<n/2){
                        ans+=a[i].b;
                        ++y;
                    }
                    else{
                        ans+=a[i].c;
                        ++z;
                    }
                }
                else if(a[i].c==a[i].ma){
                    if(z<n/2){
                        ans+=a[i].c;
                        ++z;
                    }
                    else{
                        ans+=a[i].b;
                        ++y;
                    }
                }
            }
            else if(a[i].b==a[i].mx){
                if(y<n/2){
                    ans+=a[i].b;
                    ++y;
                }
                else if(a[i].a==a[i].ma){
                    if(x<n/2){
                        ans+=a[i].a;
                        ++x;
                    }
                    else{
                        ans+=a[i].c;
                        ++z;
                    }
                }
                else if(a[i].c==a[i].ma){
                    if(z<n/2){
                        ans+=a[i].c;
                        ++z;
                    }
                    else{
                        ans+=a[i].a;
                        ++x;
                    }
                }
            }
            else if(a[i].c==a[i].mx){
                if(z<n/2){
                    ans+=a[i].c;
                    ++z;
                }
                else if(a[i].a==a[i].ma){
                    if(x<n/2){
                        ans+=a[i].a;
                        ++x;
                    }
                    else{
                        ans+=a[i].b;
                        ++y;
                    }
                }
                else if(a[i].b==a[i].ma){
                    if(y<n/2){
                        ans+=a[i].b;
                        ++y;
                    }
                    else{
                        ans+=a[i].a;
                        ++x;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        Main();
    }

    return 0;
}
