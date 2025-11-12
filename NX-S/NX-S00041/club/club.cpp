#include <bits/stdc++.h>
using namespace std;
long long a[1000000][5];
long long b[1000000][5];
long long c[1000000];
bool bj(long long a1,long long a2){
    return a[a1][b[a1][1]]>=a[a2][b[a2][1]];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,sun=0;
        cin>>n;
        for(long long i=1;i<=n;i++){
            c[i] = i;
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            long long max1=0,min1=1e9;
            for(long long j=1;j<=3;j++){
                if(a[i][j]>=max1){
                    max1 = a[i][j];
                    b[i][1]=j;
                }
                if(a[i][j]<=min1){
                    min1 = a[i][j];
                    b[i][3]=j;
                }
            }
            b[i][2] = 6 - b[i][3] - b[i][1];
        }
        sort(c+1,c+n+1,bj);
        long long r[4]={0,0,0,0};//rong liang
        for(long long i=1;i<=n;i++){
           for(long long j=1;j<=3;j++){
                if(r[b[c[i]][j]]<n/2){
                    if(i!=n&&r[b[c[i]][j]]==n/2-1&&a[c[i]][b[c[i]][j]]<a[c[i]][b[c[i]][j+1]]+a[c[i+1]][b[c[i]][j]]){
                        //cout<<'b'<<' '<<b[c[i]][j]<<' '<<a[c[i]][b[c[i]][j+1]]<<' '<<b[c[i+1]][j]<<' '<<a[c[i+1]][b[c[i+1]][j]]<<"  "<<endl;
                        r[b[c[i]][j]]++;
                        sun += a[c[i]][b[c[i]][j+1]];
                        r[b[c[i+1]][j]]++;
                        sun += a[c[i+1]][b[c[i+1]][j]];
                        i++;
                        break;
                    }
                    r[b[c[i]][j]]++;
                    sun += a[c[i]][b[c[i]][j]];
                    //cout<<'a'<<' '<<b[c[i]][j]<<' '<<a[c[i]][b[c[i]][j]]<<"  "<<endl;
                    break;
                }
           }
        }
        cout<<sun<<endl;
    }
	return 0;
}
