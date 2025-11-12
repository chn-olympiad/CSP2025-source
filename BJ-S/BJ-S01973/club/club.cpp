#include <bits/stdc++.h>
using namespace std;

int t, n;

const int maxn=1e5+10;
int tem[maxn];

struct satis{
    int a;
    int b;
    int c;
    int m;
}q[maxn];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;

        for(int i=1; i<=n; i++){
            cin>>q[i].a>>q[i].b>>q[i].c;
        }

        if(n==2){
            int one=max(q[1].a+q[2].b, q[1].a+q[2].c);
            int two=max(q[1].b+q[2].a, q[1].b+q[2].c);
            int three=max(q[1].c+q[2].a, q[1].c+q[2].b);
            int temp=max(one, two);
            cout<<max(temp, three)<<endl;
        }

		bool check=true;
        for(int i=1; i<=n; i++){
            if(q[i].c>=1 || q[i].b>=1){
                check=false;
            }
        }
        if(check==true){
            for(int i=1; i<=n; i++){
                tem[i]=q[i].a;
            }
            sort(tem+1, tem+n+1);
            int ans=0;
            for(int i=n; i>n/2; i--){
                ans+=tem[i];
            }
            cout<<ans<<endl;
        }
        
    }
}
