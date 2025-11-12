#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin >> t;
    for(long long i = 1;i <= t;i++){
        long long n,a[100005],b[100005],c[100005],suma=0,numa=0,numb=0,numc=0;
        cin >> n;
        for(long long i = 1;i <= n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(a[i]<a[j]){
                    int x = a[i];
                    a[i] = a[j];
                    a[j] = x;
                    int x = b[i];
                    b[i] = b[j];
                    b[j] = x;
                    int x = c[i];
                    c[i] = c[j];
                    c[j] = x;
                }
            }
        }
        for(long long i = 1;i <= n;i++){
            if(a[i]>b[i]&&a[i]>=c[i]&&numa<n/2){
                suma+=a[i];
                numa++;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(b[i]<b[j]){
                    int x = a[i];
                    a[i] = a[j];
                    a[j] = x;
                    int x = b[i];
                    b[i] = b[j];
                    b[j] = x;
                    int x = c[i];
                    c[i] = c[j];
                    c[j] = x;
                }
            }
        }
        for(long long i = 1;i <= n;i++){
            if(b[i]>=a[i]&&b[i]>c[i]&&numb<n/2){
                suma+=b[i];
                numb++;
            }
        }
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(c[i]<c[j]){
                    int x = a[i];
                    a[i] = a[j];
                    a[j] = x;
                    int x = b[i];
                    b[i] = b[j];
                    b[j] = x;
                    int x = c[i];
                    c[i] = c[j];
                    c[j] = x;
                }
            }
        }
        for(long long i = 1;i <= n;i++){
            if(c[i]>=b[i]&&c[i]>=a[i]&&numc<n/2){
                suma+=c[i];
                numc++;
            }
        }
        cout << suma << endl;
    }
    return 0;
}
