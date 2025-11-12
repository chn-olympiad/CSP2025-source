#include<bits/stdc++.h> 
using namespace std;
int t,n,a[100005][4],b[100005],x[5]={0,0,0,0,0},y[5]={0,0,0,0,0},ans=0;;
vector<int>num[5];
bool cmp1(int x,int y){
	return a[x][1]<a[y][1];
}
bool cmp2(int x,int y){
	return a[x][2]<a[y][2];
}
bool cmp3(int x,int y){
	return a[x][3]<a[y][3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				x[1]++; y[1]+=a[i][1];
				b[i]=1;
				num[1].push_back(i);
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				x[2]++; y[2]+=a[i][2];
				b[i]=2;
				num[2].push_back(i);
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				x[3]++; y[3]+=a[i][3];
				b[i]=3;
				num[3].push_back(i);
			}
		}
		if(x[1]<=n/2&&x[2]<=n/2&&x[3]<=n/2){
			cout<<y[1]+y[2]+y[3]+y[0]<<endl;
			continue;	
		}
		if(x[1]>n/2){
			sort(num[1].begin(),num[1].end(),cmp1);
			for(int i=0;i<x[1]-n/2;i++){
				y[1]-=a[num[1][i]][1];
				ans+=max(a[num[1][i]][2],a[num[1][i]][3]);
			}
			cout<<ans+y[1]+y[2]+y[3]<<endl;
			continue;
		}
		if(x[2]>n/2){
			sort(num[2].begin(),num[2].end(),cmp1);
			for(int i=0;i<x[2]-n/2;i++){
				y[2]-=a[num[2][i]][2];
				ans+=max(a[num[2][i]][1],a[num[2][i]][3]);
			}
			cout<<ans+y[1]+y[2]+y[3]<<endl;
			continue;
		}
		if(x[3]>n/2){
			sort(num[3].begin(),num[3].end(),cmp1);
			for(int i=0;i<x[3]-n/2;i++){
				y[3]-=a[num[3][i]][3];
				ans+=max(a[num[3][i]][2],a[num[3][i]][1]);
			}
			cout<<ans+y[1]+y[2]+y[3]<<endl;
			continue;
		}
	}
	return 0;
}
