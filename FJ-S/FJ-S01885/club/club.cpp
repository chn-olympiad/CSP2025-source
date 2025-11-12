#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int e[5];
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	return a.second.second<b.second.second;
}
int main(){
	srand(time(0));
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	freopen("debugs.txt","w",stderr);
	int tttt;
	cin>>tttt;
	int ttttt=tttt;
	while(ttttt--){
		//<<"subtask:"<<tttt-ttttt<<endl;
		memset(e,0,sizeof(e));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)	{
			cin>>a[i]>>b[i]>>c[i];
			//a[i]=rand()%2001;
			//b[i]=rand()%2001;
			//c[i]=rand()%2001;
			////<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d[i]=1;
				e[1]++;
			}	
			else if(b[i]>=a[i]&&a[i]>=c[i]){
				d[i]=2;
				e[2]++;
			}	
			else{
				d[i]=3;
				e[3]++;
			}
			//<<d[i]<<' ';
		}
		int t1=1;
		int t2=0;
		while(t1==1){
			t2++;
			//<<"round:"<<t2<<endl;
		vector<pair<int,pair<int,int>>>v;
			t1=0;
			//<<e[1]<<' '<<e[2]<<' '<<e[3]<<endl;
			if(e[1]>n/2){
				//<<"change:1"<<endl;
				t1=1;
				int t=e[1]-n/2;
				for(int i=1;i<=n;i++){
					if(d[i]==1){
						//<<i<<' ';
						v.push_back({i,{((a[i]>=b[i]&&b[i]>=c[i])?2:3),((a[i]>b[i]&&b[i]>c[i])?a[i]-b[i]:a[i]-c[i])}});
					}
				}
				//<<endl;
				sort(v.begin(),v.end(),cmp);
				for(int i=0;i<t;i++){
					//<<v[i].first<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
					e[d[v[i].first]]--;
					d[v[i].first]=v[i].second.first;
					e[v[i].second.first]++;
				}
			}
			v.clear();
			if(e[2]>n/2){
				//<<"change:2"<<endl;
				t1=1;
				int t=e[2]-n/2;
				for(int i=1;i<=n;i++){
					if(d[i]==2){
						//<<i<<' ';
						v.push_back({i,{((b[i]>=a[i]&&a[i]>=c[i])?1:3),((b[i]>=a[i]&&a[i]>=c[i])?b[i]-a[i]:b[i]-a[i])}});
					}
				}
				//<<endl;
				sort(v.begin(),v.end(),cmp);
				for(int i=0;i<t;i++){
					//<<v[i].first<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
					e[d[v[i].first]]--;
					d[v[i].first]=v[i].second.first;
					e[v[i].second.first]++;
				}
			}
			v.clear();
			if(e[3]>n/2){
				//<<"change:3"<<endl;
				t1=1;
				int t=e[3]-n/2;
				for(int i=1;i<=n;i++){
					if(d[i]==3){
						//<<i<<' ';
						v.push_back({i,{((a[i]>=b[i]&&b[i]>=c[i])?2:1),((a[i]>=b[i]&&b[i]>=c[i])?c[i]-b[i]:c[i]-a[i])}});
					}
				}
				//<<endl;
				sort(v.begin(),v.end(),cmp);
				for(int i=0;i<t;i++){
					e[d[v[i].first]]--;
					//<<v[i].first<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
					d[v[i].first]=v[i].second.first;
					e[v[i].second.first]++;
				}
			}
			//<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=((d[i]==1)?a[i]:((d[i]==2)?b[i]:c[i]));
		}
		cout<<ans<<endl;
	}
}
