#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	int t;
	cin>>t;
	while(t--){
        int n,x=0,y=0,z=0,a[100010],b[100010],c[100010],d[100010];
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(a[i]>=b[i]&&a[i]>=c[i])x++,d[i]=1;
            if(b[i]>a[i]&&b[i]>=c[i])y++,d[i]=2;
            if(c[i]>b[i]&&c[i]>a[i])z++,d[i]=3;
        }
        int maxs=n/2;
        if(x>maxs){
            int v[100010],cnt=0;
            for(int i=0;i<n&&d[i]==1;i++){
                int m=min(a[i]-b[i],a[i]-c[i]);
                v[i]=m,cnt++;
            }
            sort(v,v+cnt-1);
            for(int i=0;i<n-maxs&&d[i]==1;i++){
                if(v[i]==a[i]-b[i]&&y<maxs)d[i]=2,y++;
                else d[i]=3,z++;
            }
        }
        if(y>maxs){
            int v[100010],cnt=0;
            for(int i=0;i<n&&d[i]==2;i++){
                int m=min(b[i]-a[i],b[i]-c[i]);
                v[i]=m,cnt++;
            }
            sort(v,v+cnt-1);
            for(int i=0;i<n-maxs&&d[i]==2;i++){
                if(v[i]==b[i]-a[i]&&x<maxs)d[i]=1,x++;
                else d[i]=3,z++;
            }
        }
        if(z>maxs){
            int v[100010],cnt=0;
            for(int i=0;i<n&&d[i]==3;i++){
                int m=min(c[i]-a[i],c[i]-a[i]);
                v[i]=m,cnt++;
            }
            sort(v,v+cnt-1);
            for(int i=0;i<n-maxs&&d[i]==3;i++){
                if(v[i]==c[i]-a[i]&&x<maxs)d[i]=1,x++;
                else d[i]=2,y++;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(d[i]==1)cnt+=a[i];
            else if(d[i]==2)cnt+=b[i];
            else if(d[i]==3)cnt+=c[i];
        }
        cout<<cnt;
    }
	return 0;
}
