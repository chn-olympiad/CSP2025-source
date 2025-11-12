#include<bits/stdc++.h>
using namespace std;
struct M{
	int a;
	int b;
	int c;
	int best;
	int maxn;
	int minn;
} arr[1000100];
bool cmp(M a,M b){
	if(a.best==b.best)return a.maxn>b.maxn;
	return a.best>b.best;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,p1=0,p2=0,p3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			arr[i].maxn=max(max(arr[i].a,arr[i].b),arr[i].c);
			arr[i].minn=min(min(arr[i].a,arr[i].b),arr[i].c);
			arr[i].best=arr[i].maxn-arr[i].minn;
		}
		sort(arr+1,arr+1+n,cmp);
		//for(int i=1;i<=n;i++)cout<<arr[i].best<<" ";
		//cout<<endl;
		for(int i=1;i<=n;i++){
		//cout<<arr[i].best<<endl;
			if(arr[i].maxn==arr[i].a&&arr[i].a!=-1){
				if(p1<(n/2)){
					p1++;
					ans+=arr[i].maxn;
					//cout<<'a'<<i<<" "<<arr[i].maxn<<endl;
					continue;
				}
				else{
					//cout<<'e';
					arr[i].a=-1;
					arr[i].maxn=max(arr[i].b,arr[i].c);
					arr[i].minn=min(arr[i].b,arr[i].c);
					arr[i].best=arr[i].maxn-arr[i].minn;
					sort(arr+i,arr+1+n,cmp);
					i--;
					continue;
				}
			}
			if(arr[i].maxn==arr[i].b&&arr[i].b!=-1){
				if(p2<(n/2)){
					p2++;
					ans+=arr[i].maxn;
					//cout<<'b'<<i<<" "<<arr[i].maxn<<endl;
					continue;
				}
				else{
					//cout<<'f';
					arr[i].b=-1;
					arr[i].maxn=max(arr[i].a,arr[i].c);
					arr[i].minn=min(arr[i].a,arr[i].c);
					arr[i].best=arr[i].maxn-arr[i].minn;
					sort(arr+i,arr+1+n,cmp);
					i--;
					continue;
				}
			}
			if(arr[i].maxn==arr[i].c&&arr[i].c!=-1){
				if(p3<(n/2)){
					p3++;
					ans+=arr[i].maxn;
					//cout<<'c'<<i<<" "<<arr[i].maxn<<endl;
					continue;
				}
				else{
					//cout<<'g';
					arr[i].c=-1;
					arr[i].maxn=max(arr[i].b,arr[i].a);
					arr[i].minn=min(arr[i].b,arr[i].a);
					arr[i].best=arr[i].maxn-arr[i].minn;
					sort(arr+i,arr+1+n,cmp);
					i--;
					continue;
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}

