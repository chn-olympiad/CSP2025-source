#include <bits/stdc++.h>
using namespace std;
long long a[100009][3];
int b[100009][3];
long long c[100009];
long long d[100009];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    long long n;
    long long ans,cnt[3];
    for(int o=0;o<t;o++){
        cin>>n;
        ans = 0;
        cnt[0] = 0;
        cnt[1] = 0;
        cnt[2] = 0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2]){
                b[i][0] = 0;
                b[i][1] = 1;
                b[i][2] = 2;
            }
            else if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1]){
                b[i][0] = 0;
                b[i][1] = 2;
                b[i][2] = 1;
            }
            else if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2]){
                b[i][0] = 1;
                b[i][1] = 0;
                b[i][2] = 2;
            }
            else if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0]){
                b[i][0] = 1;
                b[i][1] = 2;
                b[i][2] = 0;
            }
            else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0]){
                b[i][0] = 2;
                b[i][1] = 1;
                b[i][2] = 0;
            }
            else if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1]){
                b[i][0] = 2;
                b[i][1] = 0;
                b[i][2] = 1;
            }
        }
        for(int i=0;i<n;i++){
            ans += a[i][b[i][0]];
            cnt[b[i][0]]++;
            c[i] = a[i][b[i][0]] - a[i][b[i][1]];
        }
        long long wrong = -1;
        for(int i=0;i<3;i++){
            if (cnt[i]>n/2){
                wrong = i;
            }
        }
        if(wrong==-1){
            cout<<ans<<endl;
        }
        else{
            long long pos = 0;
            for(int i=0;i<n;i++){
                if(b[i][0]==wrong){
                    d[pos] = c[i];
                    pos++;
                }
            }
            sort(d,d+pos);
            for(int j=0;j<cnt[wrong]-n/2;j++){
                ans -= d[j];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}