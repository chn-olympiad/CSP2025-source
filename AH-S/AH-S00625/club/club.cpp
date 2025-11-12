#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int x,y,z;
	int id;
}a[1000005];
vector<node>vt[4];
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=3;i++) vt[i].clear();
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		if(n==2){
			int a1,b1,c1,d1,e1,f1;
			cin>>a1>>b1>>c1>>d1>>e1>>f1;
			cout<<max({a1+e1,a1+f1,b1+d1,b1+f1,c1+d1,c1+f1});
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) vt[1].push_back(a[i]),ans+=a[i].x;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) vt[2].push_back(a[i]),ans+=a[i].y;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) vt[3].push_back(a[i]),ans+=a[i].z;
		}
		for(int i=1;i<=3;i++){
			if(i==1) sort(vt[i].begin(),vt[i].end(),cmp1);
			else if(i==2) sort(vt[i].begin(),vt[i].end(),cmp2);
			if(i==1){
				if(vt[1].size()>n/2){
					for(int j=0;j<(vt[i].size()-n/2);j++){
						if(a[vt[i][j].id].y>a[vt[i][j].id].z&&vt[2].size()!=n/2) vt[2].push_back(vt[i][j]),ans-=(vt[i][j].x-vt[i][j].y);
						else vt[3].push_back(vt[i][j]),ans-=(vt[i][j].x-vt[i][j].z);
					}
				}
			}
			else if(i==2){
				if(vt[2].size()>n/2){
					for(int j=0;j<(vt[i].size()-n/2);j++){
						vt[3].push_back(vt[i][j]);
						ans-=(vt[i][j].y-vt[i][j].z);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//struct od{
	//long long num,id;
//};
//struct node{
	//od x,y,z;
	//od Max;
	//int id;
//}a[100005];

//bool cmp1(node a,node b){
	//return a.z.num>b.z.num;
//}
//bool cmp2(node a,node b){
	//return a.y.num>b.y.num;
//} 
//bool cmp3(node a,node b){
	//return a.x.num>b.x.num;
//} 
//bool vis[100005];
//int n;
//int mp[4];
//int main(){
		//freopen("club2.in","r",stdin);
	////freopen("club.out","w",stdout);
	//int t;
	//cin>>t;
	//while(t--){
		//memset(mp,0,sizeof(mp));
		//memset(vis,0,sizeof(vis));
		//memset(a,0,sizeof(a));
		//cin>>n;
		//if(n!=2){
			//for(int i=1;i<=n;i++){
				//a[i].id=i;
				//cin>>a[i].x.num>>a[i].y.num>>a[i].z.num;
				//a[i].x.id=1,a[i].y.id=2,a[i].z.id=3;
				//if(a[i].x.num>=a[i].Max.num) a[i].Max={a[i].x.num,1};
				//if(a[i].y.num>=a[i].Max.num) a[i].Max={a[i].y.num,2};
				//if(a[i].z.num>=a[i].Max.num) a[i].Max={a[i].z.num,3};
			//}
			//long long ans=0;
			//mp[3]=0;
			//sort(a+1,a+n+1,cmp1);
			//for(int i=1;i<=n;i++){
				//if(vis[a[i].id]) continue;
				//if(mp[3]==n/2) break;
				//if(a[i].z.id==a[i].Max.id){
					//ans+=a[i].z.num;
					//mp[3]++;
					//vis[a[i].id]=1;
				//}
			//}
			//sort(a+1,a+n+1,cmp2);
			//mp[2]=0;
			//for(int i=1;i<=n;i++){
				//if(vis[a[i].id]) continue;
				//if(mp[2]==n/2) break;
				//if(a[i].y.id==a[i].Max.id){
					//ans+=a[i].y.num;
					//mp[2]++;
					//vis[a[i].id]=1;
				//}
			//}
			//sort(a+1,a+n+1,cmp3);
			//mp[1]=0;
			//for(int i=1;i<=n;i++){
				//if(vis[a[i].id]) continue;
				//if(mp[1]==n/2) break;
				//if(a[i].x.id==a[i].Max.id){
					//ans+=a[i].x.num;
					//mp[1]++;
					//vis[a[i].id]=1;
				//}
			//}
			//for(int i=1;i<=n;i++){
				//if(!vis[a[i].id]){
					//if(a[a[i].id].x.num>=a[a[i].id].y.num||a[a[i].id].x.num>=a[a[i].id].z.num){
						//if(mp[1]<n/2) mp[1]++,ans+=a[a[i].id].x.num,vis[a[i].id]=1;
					//}
					//else if(a[a[i].id].y.num>=a[a[i].id].x.num||a[i].y.num>=a[i].z.num){
						//if(mp[2]<n/2) mp[2]++,ans+=a[a[i].id].y.num,vis[a[i].id]=1;
					//}
					//else if(a[a[i].id].z.num>=a[a[i].id].x.num||a[a[i].id].z.num>=a[i].y.num){
						//if(mp[3]<n/2) mp[3]++,ans+=a[a[i].id].z.num,vis[a[i].id]=1;
					//}
				//}
			//}
			//cout<<ans<<endl;
		//}
		//else{
			//int a1,b1,c1,d1,e1,f1;
			//cin>>a1>>b1>>c1>>d1>>e1>>f1;
			//cout<<max({a1+e1,a1+f1,b1+d1,b1+f1,c1+d1,c1+f1});
		//}
	//} 
	
	//return 0;
//}
