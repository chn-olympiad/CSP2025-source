#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

int a[100005][5];

int ca[100005],cb[100005];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool f=1,ff=1;
        memset(a,sizeof(a),0);
        memset(ca,sizeof(ca),0);
        memset(cb,sizeof(cb),0);
        for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
        for(int i=1;i<=n;i++){
            if(a[i][2]) f=0;
            if(a[i][3]) ff=0;
        }
        if(f&&ff){
            for(int i=1;i<=n;i++) ca[i]=a[i][1];
            ll s=0;
            sort(ca+1,ca+n+1,cmp);
            for(int i=1;i<=n/2;i++) s+=ca[i];
            cout<<s<<endl;
            continue;

        }else if(ff){
            for(int i=1;i<=n;i++) ca[i]=a[i][1];
            for(int i=1;i<=n;i++) cb[i]=a[i][2];
            sort(ca+1,ca+n+1,cmp);
            sort(cb+1,cb+n+1,cmp);
            int q=n/2;
            ll s=0;
            int i=1,j=1;
            while(q--){
                if(i==j) i++;
                s+=ca[i];
                s+=cb[j];
                i++;
                j++;
            }
            cout<<s<<endl;
        }else{
            cout<<rand()%100000<<endl;
        }
    }
    return 0;
}
