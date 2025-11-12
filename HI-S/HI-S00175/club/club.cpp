#include<bits/stdc++.h>
using namespace std;
int T,afz[100010];
pair<int,int> a[100010][3];
bool cmp(int x,int y){
	return a[x][2]>a[y][2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n,b[3]={0,0,0},sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0].first>>a[i][1].first>>a[i][2].first;
			a[i][0].second=0;
			a[i][1].second=1;
			a[i][2].second=2;
			sort(a[i],a[i]+3);
			afz[i]=i;
		}
		sort(afz+1,afz+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(b[a[afz[i]][2].second]<n/2){
				sum+=a[afz[i]][2].first;
				b[a[afz[i]][2].second]++;
			} 
			else if(b[a[afz[i]][1].second]<n/2){
				sum+=a[afz[i]][1].first;
				b[a[afz[i]][1].second]++;
			} 
			else if(b[a[afz[i]][0].second]<n/2){
				sum+=a[afz[i]][0].first;
				b[a[afz[i]][0].second]++;
			} 
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/**/
