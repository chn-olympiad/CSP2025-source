#include<bits/stdc++.h>
using namespace std;
bool b[100005];
vector<pair<int,int> > v1,v2;
int cf[100005][5];
int main(){
	//成员对第三个部门好感度为零
	//按照差值排序 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==2){
			int a[4],b[4],ans=0;
			cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						ans=max(ans,a[i]+b[j]);
					}
				}
			}
			cout<<ans<<"\n";
		}
		else{
			long long cnt=0,cnt1=0,cnt2=0,ans=0,maxi;
			for(int i=1;i<=n;i++){
				cin>>cf[i][1]>>cf[i][2]>>cf[i][3];
				cf[i][3]-=cf[i][2];
				cf[i][2]-=cf[i][1];
			}
			for(int j=1;j<=3;j++){
				v1.clear();
				v2.clear();
				cnt=cnt1=cnt2=0;
				for(int i=1;i<=n;i++){
					cf[i][2]+=cf[i][1];
					cf[i][3]+=cf[i][2];
					if(j==2){
						swap(cf[i][1],cf[i][2]);
					}
					else if(j==3){
						swap(cf[i][1],cf[i][3]);
					}
					cnt+=cf[i][1];
					
					cf[i][3]-=cf[i][2];
					cf[i][2]-=cf[i][1];
					if(cf[i][3]>0){
						v2.push_back({cf[i][3],i});
					}
					v1.push_back({cf[i][2],i});
					b[i]=0;
				}
			//	cout<<cnt<<"  cnt\n";
				sort(v1.begin(),v1.end());
				sort(v2.begin(),v2.end());
				pair<int,int> u;
				for(int i=v2.size()-1;i>=0;i--){
					u=v2[i];
					if(u.first<=0){
						break;
					}
					if(cnt2>=n/2){
						break;
					}
				//	cout<<u.first+cf[u.second][2]<<" 1+\n";
					cnt=cnt+u.first+cf[u.second][2];
					b[u.second]=1;
					cnt2++;
				}
				for(int i=v1.size()-1;i>=0;i--){
					u=v1[i];
					if(u.first<=0&&cnt1+cnt2>=n/2){
						break;
					}
					if(cnt1>=n/2){
						break;
					}
					if(b[u.second]){
				//		cout<<"123"<<" "<<i<<"\n";
						continue;
					}
				//	cout<<u.first<<" "<<i<<" 2+\n";
					cnt+=u.first;
					cnt1++;
				}
				if(ans<cnt){
					ans=cnt;
					maxi=j;
				}
		//		cout<<"\n";
			}
			cout<<ans;
			//cout<<" "<<maxi<<"   ans";
			cout<<"\n";
		}
	}
} 
