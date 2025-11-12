#include<bits/stdc++.h>
#define int long long
using namespace std;
void testread(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
}
int n;
int a[100010][3];
int num[3];
int id[3][100010];
int de[100010];
int sot[100010];
int nxt[100010];
bool cmp(int a,int b){
    return de[a]>de[b];
}
signed main(){
    testread();
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        cin>>n;
        //cout<<n<<endl;
        for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        int sum=0;
        num[0]=num[1]=num[2]=0;
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                sum+=a[i][0],num[0]++,id[0][num[0]]=i;
                de[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
                if(a[i][1]>a[i][2])nxt[i]=1;
                else nxt[i]=2;
            }
            else if(a[i][0]<=a[i][1]&&a[i][1]>=a[i][2]){
                sum+=a[i][1],num[1]++,id[1][num[1]]=i;
                de[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
                if(a[i][0]>a[i][2])nxt[i]=0;
                else nxt[i]=2;
            }
            else{
                sum+=a[i][2],num[2]++,id[2][num[2]]=i;
                de[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
                if(a[i][0]>a[i][1])nxt[i]=0;
                else nxt[i]=1;
            }
        }
        for(int i=0;i<=2;i++){
            if(num[i]>n/2){
                for(int j=1;j<=num[i];j++){
                    sot[j]=id[i][j];
                }
                sort(sot+1,sot+1+num[i],cmp);
                int j=num[i];
                while(j>n/2){
                    sum-=de[sot[j]];
                    j--;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

