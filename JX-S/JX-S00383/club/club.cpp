#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct club{
    int fi,se,th;
}a[N];
bool cmp(club a,club b){
    if(a.fi>b.fi){
        return 1;
    }
    else{
        if(a.fi==b.fi){
            if(a.se>b.se){
                return 1;
            }
            else{
                if(a.th>b.th){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        else{
            return 0;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].fi>>a[i].se>>a[i].th;
        }
        sort(a+1,a+n+1,cmp);
        if(n==2){
            if(a[1].fi>max(a[1].se,a[1].th) && a[2].fi>max(a[2].se,a[2].th)){
                cout<<max(a[1].fi+max(a[2].se,a[2].th),a[2].fi+max(a[1].se,a[1].th));
                cout<<"\n";
                continue;
            }
            else if(a[1].se>max(a[1].fi,a[1].th) && a[2].se>max(a[2].fi,a[2].th)){
                cout<<max(a[1].se+max(a[2].fi,a[2].th),a[2].se+max(a[1].fi,a[1].th));
                cout<<"\n";
                continue;

            }
            else if(a[1].th>max(a[1].se,a[1].fi) && a[2].th>max(a[2].se,a[2].fi)){
                cout<<max(a[1].th+max(a[2].se,a[2].fi),a[2].th+max(a[1].se,a[1].fi));
                cout<<"\n";
                continue;
            }
        }
        long long k=n/2,sum=0;
        long long one=0,two=0,three=0;
        for(int i=1;i<=n;i++){
            if(a[i].fi>max(a[i].se,a[i].th)){
                if(one<k){
                    one++;
                    sum+=a[i].fi;
                    continue;
                }
                if(a[i].se>a[i].th){
                    if(two<k){
                        two++;
                        sum+=a[i].se;
                        continue;
                    }
                    three++;
                    sum+=a[i].th;
                    continue;
                }
                else{
                    if(three<k){
                        three++;
                        sum+=a[i].th;
                        continue;
                    }
                    two++;
                    sum+=a[i].se;
                    continue;
                }
            }
            else if(a[i].se>max(a[i].fi,a[i].th)){
                if(two<k){
                    two++;
                    sum+=a[i].se;
                    continue;
                }
                if(a[i].fi>a[i].th){
                    if(one<k){
                        one++;
                        sum+=a[i].fi;
                        continue;
                    }
                    three++;
                    sum+=a[i].th;
                    continue;
                }
                else{
                    if(three<k){
                        three++;
                        sum+=a[i].th;
                        continue;
                    }
                    one++;
                    sum+=a[i].fi;
                    continue;
                }
            }
            else{
                if(three<k){
                    three++;
                    sum+=a[i].th;
                    continue;
                }
                if(a[i].fi>a[i].se){
                    if(one<k){
                        one++;
                        sum+=a[i].fi;
                        continue;
                    }
                    two++;
                    sum+=a[i].se;
                    continue;
                }
                else{
                    if(two<k){
                        two++;
                        sum+=a[i].se;
                        continue;
                    }
                    one++;
                    sum+=a[i].fi;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

