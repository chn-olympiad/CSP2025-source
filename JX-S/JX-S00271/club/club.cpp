#include <bits/stdc++.h>

using namespace std;
int t,n;
int a[100005];
int b[100005];
int c[100005];
bool cmp(int a,int b){
    return a>b;
}
void twoAthree(int n){
    sort(a+1,a+n+1,cmp);
    int sum=0;
    for(int i=1;i<=n/2;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","W",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0) cnt2++;
            if(c[i]==0)  cnt3++;
        }
        if(cnt2==n&&cnt3==n) {
            twoAthree(n);
            continue;
        }
    }



    return 0;
}
