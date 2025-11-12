#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int city1;
	int city2;
	int money;
}city[10001];
struct v{
	int c;
	int a[10001];
}village[10001];
int ans=0
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>city[i].city1>>city[i].city2>>city[i].money;
	for(int i=1;i<=k;i++){
		cin>>village[i].c;
		for(int j=1;j<=n;j++)cin>>village[i].a[j];
	}
	if(k==0){
        for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			if(city[i].money>city[j].money)swap(city[i],city[j]);
		}
        }
        if(m==n-1){
            for(int i=1;i<=m;i++)ans+=city[i].money;
            cout<<ans;
            return 0;
        }
        else{
            for(int i=1;i<=n-1;i++)ans+=city[i].money;
            cout<<ans;
            return 0;
        }
    }
	else{
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                for(int k=1;k<=n;k++){
                    if(city[i].money>city[j].money)swap(city[i],city[j]);
                    if(village[i].a[k]>city[i].money)swap(city[i],village[i]);
                }
            }
        }
        for(int i=1;i<=n-1;i++)ans+=city[i].money;
        cout<<ans;
	}
	return 0;
}
