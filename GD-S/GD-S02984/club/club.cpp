#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
}; 
node a[100005];
int f[505][505][505];
int lst[505][505][505];
void solve(){
	/*
	cin>>n;
	vector<pair<int,int>>x,y,z;
	int cnt=0;
	for(int i=1;i<=n;i++){
		//cin>>arr[i].a>>arr[i].b>>arr[i].c;
		scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
		if(arr[i].a>arr[i].b&&arr[i].a>arr[i].c){//max=a 
			x.push_back({arr[i].a,i});
		}
		if(arr[i].b>arr[i].a&&arr[i].b>arr[i].c){//max=b
			y.push_back({arr[i].b,i});
		}
		if(arr[i].c>arr[i].b&&arr[i].c>arr[i].a){//max=c
			z.push_back({arr[i].c,i});
		}
		cnt+=max({arr[i].a,arr[i].b,arr[i].c});
	} 
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(z.begin(),z.end());
	while(!(x.size()<=n/2&&y.size()<=n/2&&z.size()<=n/2)){
	
		if(x.size()>n/2){
			for(int i=0;i<(x.size()-n/2);i++){
				int pos=x[i].second; 
				if(arr[pos].b>arr[pos].c){
					y.push_back({arr[pos].b,pos});
				}else{
					z.push_back({arr[pos].c,pos});
				}
				cnt-=arr[pos].a-max(arr[pos].b,arr[pos].c);
				x.erase(pos+x.begin());
			}
		}
		if(y.size()>n/2){
			for(int i=0;i<(y.size()-n/2);i++){
				int pos=y[i].second;
				if(arr[pos].a>arr[pos].c){
					x.push_back({arr[pos].a,pos});
				}else{
					z.push_back({arr[pos].c,pos});
				}
				cnt-=arr[pos].b-max(arr[pos].a,arr[pos].c);
				y.erase(pos+y.begin());
			}
		}
		if(z.size()>n/2){
			for(int i=0;i<(z.size()-n/2);i++){
				int pos=z[i].second;
				if(arr[pos].b>arr[pos].a){
					y.push_back({arr[pos].b,pos});
				}else{
					x.push_back({arr[pos].a,pos});
				}
				cnt-=arr[pos].c-max(arr[pos].b,arr[pos].a);
				z.erase(pos+z.begin());
			}
		}
	}
	cout<<cnt<<endl;*/
	memset(f,0,sizeof(f));
	memset(lst,0,sizeof(lst));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b>>a[i].c; 
	int ans=-1e9;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){
				for(int l=0;l<n/2;l++){
					f[j][k][l]=max({lst[j+1][k][l]+a[i].a,lst[j][k+1][l]+a[i].b,lst[j][k][l+1]+a[i].c});
					if(i==n) ans=max(ans,f[j][k][l]);
				} 
			}
		}
		for(int j=0;j<n/2;j++){
			for(int k=0;k<n/2;k++){
				for(int l=0;l<n/2;l++){
					lst[j][k][l]=f[j][k][l];
				} 
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

