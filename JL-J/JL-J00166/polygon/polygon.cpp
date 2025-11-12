#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a;
    cin>>a;
    int b[a][2];
    for(int i=0;i<a;i++){
        cin>>b[i][0];
    }
    long long c=1;
    for(int i=0;i<a;i++){
        c*=2;
    }
    int d,e,f,g,h,k=0,m,n;
    vector<int> l;
    for(int i=0;i<c;i++){
        for(int j=0;j<a;j++){
            b[j][1]=0;
        }
        d=0;
        e=i;
        f=0;
        m=c;
        while(e>0){
            m/=2;
            if(e>=m){
                b[d][1]=1;
                e-=m;
                f++;
            }
            d++;
        }
        if(f>=3){
            for(int j=0;j<a;j++){
                if(b[j][1]){
                    l.push_back(b[j][0]);
                }
            }
            g=0;
            h=l[0];
            n=l.size();
            for(int j=0;j<n;j++){
                g+=l[0];
                if(l[0]>h){
                    h=l[0];
                }
                l.erase(l.begin());
            }
            if(g>h*2){
                k++;
            }
        }

    }
    cout<<k%998%244%353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
