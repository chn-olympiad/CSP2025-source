#include<bits/stdc++.h>
using namespace std;

int n,m,temp_;
vector<int> OPK;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>temp_;
        OPK.push_back(temp_);
    }
    const int aSeat=OPK[0];
    sort(OPK.begin(),OPK.end(),cmp);
    int brs=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(aSeat==OPK[brs]){
                if(i%2==0) j=n-j+1;
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
            brs++;
        }
    }
    return 0;
}