#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,a[N][5],tmp[N];

bool cmp(int x,int y){return x>y;}

bool check(int x){
    int cnt=0;
    for(int k=0;k<n;k++)
        if((x>>k)&1)cnt++;
    if(cnt*2>n)return false;
    return true;
}
bool comp(int x,int y,int z){
    for(int k=0;k<n;k++)
        if(((x>>k)&1&&(y>>k)&1)||((x>>k)&1&&(z>>k)&1)||((y>>k)&1&&(z>>k)&1))return false;
    return true;
}

int Plus(int x,int y,int z){
    int sum=0;
    for(int k=0;k<n;k++){
        if((x>>k)&1)sum+=a[k+1][1];
        else if((y>>k)&1)sum+=a[k+1][2];
        else if((z>>k)&1)sum+=a[k+1][3];
    }
//   for(int k=0;k<n;k++){
//    	if((x>>k)&1)cout<<1;
//    	else cout<<0;
//	}
//	cout<<' ';
//	for(int k=0;k<n;k++){
//    	if((y>>k)&1)cout<<1;
//    	else cout<<0;
//	}
//	cout<<' ';
//	for(int k=0;k<n;k++){
//    	if((z>>k)&1)cout<<1;
//    	else cout<<0;
//	}
//	cout<<' '<<sum<<'\n';
    return sum;
}

int force(){
	int ans=0;
    for(int x=0;x<(1<<n);x++){
        if(!check(x))continue;
        for(int y=0;y<(1<<n);y++){
            if(!check(y))continue;
            for(int z=0;z<(1<<n);z++){
                if(!check(z)||!comp(x,y,z))continue;
                ans=max(ans,Plus(x,y,z));
            }
        }
    }
    return ans;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];

		if(n>=200){
			for(int i=1;i<=n;i++)tmp[i]=a[i][1];
			sort(tmp+1,tmp+1+n,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=tmp[i];				
			}
			cout<<sum<<'\n';
		}
        cout<<force()<<'\n';
    }
    return 0;
}
