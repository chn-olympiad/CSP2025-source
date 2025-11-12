#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5];
vector<int> b[5];
void solve(){
    b[1].clear();
    b[2].clear();
    b[3].clear();
    cin>>n;
    int li=n/2;
    int x=0,y=0,z=0;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        int s=max(a[i][1],max(a[i][2],a[i][3]));
        sum+=(long long)s;
        if(s==a[i][1]){
            x++,b[1].push_back(min(s-a[i][2],s-a[i][3]));
            //cout<<1<<" "<<b[1][x-1]<<endl;
        }
        else if(s==a[i][2]){
            y++,b[2].push_back(min(s-a[i][1],s-a[i][3]));
            //cout<<2<<" "<<b[2][y-1]<<endl;
        }
        else {
            z++,b[3].push_back(min(s-a[i][1],s-a[i][2]));
            //cout<<3<<" "<<b[3][z-1]<<" "<<s<<" "<<min(s-a[i][1],s-a[i][2])<<endl;
        }
    }
    //cout<<endl<<x<<" "<<y<<" "<<z;
    if(x<=li&&y<=li&&z<=li){
        cout<<sum<<endl;return;
    }
    if(x>li){
        sort(b[1].begin(),b[1].end());
        //for(int i=0;i<b[1].size();i++)cout<<b[1][i]<<" ";
        int l=x-li;
        for(int i=0;i<l;i++){
            sum-=b[1][i];
        }
        cout<<sum<<endl;
    }
    else if(y>li){
        sort(b[2].begin(),b[2].end());
        //for(int i=0;i<b[2].size();i++)cout<<b[2][i]<<" ";
        int l=y-li;
        for(int i=0;i<l;i++){
            sum-=b[2][i];
        }
        cout<<sum<<endl;
    }
    else{
        sort(b[3].begin(),b[3].end());
        //for(int i=0;i<b[2].size();i++)cout<<b[2][i]<<" ";
        int l=z-li;
        for(int i=0;i<l;i++){
            sum-=b[3][i];
        }
        cout<<sum<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)solve();
    return 0;
}