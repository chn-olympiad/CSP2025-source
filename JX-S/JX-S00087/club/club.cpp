#include<bits/stdc++.h>
using namespace std;
int n,t,x,y,z;
long long ans;
int a[100005][3],s[3][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        x=0,y=0,z=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                    ans+=a[i][1];x++;
                    s[1][x]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
                    }
            if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                    ans+=a[i][2];y++;
                    s[2][y]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
                    }
            if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                    ans+=a[i][3];z++;
                    s[3][z]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
                }
        }
        if(x>n/2){
            sort(s[1]+1,s[1]+x+1);
            for(int i=1;i<=x-(n/2);i++){
                ans-=s[1][i];
            }
        }
        if(y>n/2){
            sort(s[2]+1,s[2]+y+1);
            for(int i=1;i<=y-(n/2);i++){
                ans-=s[2][i];
  
            }
        }
        if(z>n/2){
            sort(s[3]+1,s[3]+z+1);
            for(int i=1;i<=z-(n/2);i++){
                ans-=s[3][i];
            }
        }
        cout<<ans;
    }
    return 0;}
