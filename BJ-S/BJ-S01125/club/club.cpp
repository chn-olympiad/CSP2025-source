#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,a[N][5],best[N],arr[N];
int f,sum,ans;
bool cmp(int x,int y){
    if(a[x][f]>a[y][f]) return 1;
    if(a[x][f]<a[y][f]) return 0;
    return f==best[x]&&f!=best[y];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][best[i]])best[i]=j;
			}
		
		int cnt[4]={0};
		for(int i=1;i<=n;i++){
			ans+=a[i][best[i]];
			cnt[best[i]]++;
		}
		for(int i=1;i<=3;i++)if(cnt[i]>n/2)ans=0;
		
        for(int i=1;i<=n;i++) arr[i]=i;
        for(f=1;f<=3;f++){
            sum=0;
            sort(arr+1,arr+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                sum+=a[arr[i]][f];
            }
            for(int i=n/2+1;i<=n;i++){
                int tmp=-1;
                for(int j=1;j<=3;j++)if(j!=f&&a[arr[i]][j]>tmp)tmp=a[arr[i]][j];
                sum+=tmp;
            }
            if(sum>ans) ans=sum;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
