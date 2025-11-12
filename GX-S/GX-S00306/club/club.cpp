#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int t,n;
int p[3][N];

bool cmp(int a,int b){
    return a>b;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin>>n;
        int f1,f2,f3;
        f1 = 0;
        f2 = 0;
        f3 = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            int ar,br,cr;
            cin>>ar>>br>>cr;
            if(ar >= br && ar >= cr){
                sum += ar;
                p[0][f1] = max(br-ar,cr-ar);
                f1++;
            }else if(br >= ar && br >= cr){
                sum += br;
                p[1][f2] = max(ar-br,cr-br);
                f2++;
            }else{
                sum += cr;
                p[2][f3] = max(ar-cr,br-cr);
                f3++;
            }
        }
        if(f1 <= n/2 && f2 <= n/2 && f3 <= n/2){
            cout<<sum<<endl;
            continue;
        }else if(f1 > n/2){
            sort(p[0],p[0]+f1,cmp);
            for(int i=0;i<f1-n/2;i++){
                sum += p[0][i];
            }
        }else if(f2 > n/2){
            sort(p[1],p[1]+f2,cmp);
            for(int i=0;i<f2-n/2;i++){
                sum += p[1][i];
            }
        }else{
            sort(p[2],p[2]+f3,cmp);
            for(int i=0;i<f3-n/2;i++){
                sum += p[2][i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
