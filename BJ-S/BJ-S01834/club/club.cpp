#include<bits/stdc++.h>
using namespace std;

struct node{
    int num,l1,l2,l3;
}a[100010];
bool sortrule(node a,node b){
    return a.l2 > b.l2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool flag = 0;
        for(int i = 1; i <= n; i++){
            cin>>a[i].l1>>a[i].l2>>a[i].l3;
            a[i].num = i;
            if(a[i].l1 != 0 || a[i].l3 != 0){
                flag = 1;
            }
        }
        if(!flag){
            int ans = 0;
            sort(a+1,a+n+1,sortrule);
            for(int i = 1; i <= n/2; i++){
                ans += a[i].l2;
            }
            cout<<ans<<endl;
            return 0;
        }
        int ans = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].l1 > a[i].l2){
                if(a[i].l1 > a[i].l3 && cnt1 < n/2){
                    ans += a[i].l1;
                    cnt1++;
                    continue;
                }
                else if(cnt3 < n/2){
                    ans += a[i].l3;
                    cnt3++;
                    continue;
                }
                else if(cnt1 < n/2){
                    ans += a[i].l2;
                    cnt2++;
                    continue;
                }
                else if(cnt2 < n/2){
                    ans += a[i].l1;
                    cnt1++;
                    continue;
                }
            }
            else{
                if(a[i].l2 > a[i].l3 && cnt2 < n/2){
                    ans += a[i].l2;
                    cnt2++;
                    continue;
                }
                else if(cnt3 < n/2){
                    ans += a[i].l3;
                    cnt3++;
                    continue;
                }
                else if(cnt2 < n/2){
                    ans += a[i].l2;
                    cnt2++;
                    continue;
                }
                else if(cnt1 < n/2){
                    ans += a[i].l1;
                    cnt1++;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
