#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,ans,m[3];
int b[N][3];
vector<int>v1;
int bel[N],ebl[N];
void slove(){
	m[0]=m[1]=m[2]=ans=0;
	v1.clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>b[i][j];
		}
		int mm=max({b[i][0],b[i][1],b[i][2]});
		ans+=mm;
		for(int j=0;j<3;j++)
			if(mm==b[i][j]){
				m[j]++;
				int m2=-1;
				for(int k=0;k<3;k++)
					if(k!=j)
						m2=max(m2,b[i][k]);
				ebl[i]=m2-mm;
				bel[i]=j;
			}
	}
	// sort(vala+1,vala+1+3*n);
	// for(int i=3*n;i>=1;i--){
	// 	int val=vala[i].first,num=a[vala[i].second].num,club=a[vala[i].second].club;
	// 	if(vis[num])continue;
	// 	ans+=val;
	// 	m[club]++;
	// 	vis[num]=1;
	// 	bel[num]=club;
	// 	// ebl[num]=max(val-b[num][(club+1)%3],)
	// }
	// for(int i=1;i<=n;i++)
	// 	cout<<ebl[i]<<" ";
	// cout<<endl;
	for(int i=0;i<3;i++){
		if(m[i]*2>n){
			for(int j=1;j<=n;j++)
				if(bel[j]==i)
					v1.push_back(ebl[j]);
			// for(auto x:v1)
			// 	cout<<x<<" ";
			// cout<<endl;
			sort(v1.begin(), v1.end());
			for(int k=1;k<=m[i]-(n/2);k++)
				ans+=v1[v1.size()-k];
		}
	}

	// cout<<endl;
	cout<<ans<<endl;
	// cout<<"*";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		slove();
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,ans,m[3];
struct data
{
	int club;
	int num;
}a[N*3];
pair<int,int>vala[N*3];
//tuple<int,int,int>a[N*3];
int b[N][3];
bitset<N>vis;
//typedef tuple<int,int,int,int> reg;
int rtot,c[N];//c->choose
struct reg{
	int toclub;//to
	int num;
};
vector<reg> r;

priority_queue<pair<int,int> >q[3];//regret_val,num
priority_queue<int>q1[3];
void slove(){
	m[0]=m[1]=m[2]=ans=0;rtot=0;
	r.clear();
	vis.reset();
	r.push_back({0,0});
	// memset(c,0,sizeof c);
	for(int i=0;i<3;i++)
		while(!q[i].empty())
			q[i].pop();
	for(int i=0;i<3;i++)
		while(!q1[i].empty())
			q1[i].pop();
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>b[i][j];
			a[i*3-2+j]={j,i};
			vala[i*3-2+j]={b[i][j],i*3-2+j};
		}
	}
	sort(vala+1,vala+1+3*n);
	for(int i=3*n;i>=1;i--){
		int val=vala[i].first,num=a[vala[i].second].num,club=a[vala[i].second].club;
		if(vis[num])continue;
		if(m[club]*2==n){//continue;
			// int reval,qt;
			// do{
			// 	reval=q[club].top().first,qt=q[club].top().second;
			// 	q[club].pop();
			// }
			// while(0&&c[r[qt].num]!=club);
			int reval=q1[club].top();
			q1[club].pop();
			if(val+reval>0){
				ans+=reval;

		// cout<<"+"<<reval<<endl;
				m[club]--;
				// c[r[qt].num]=r[qt].toclub;
				// m[r[qt].toclub]++;
		// for(int j=0;j<3;j++)
		// 	if(j!=r[qt].toclub){
		// 		rtot++;
		// 		r.push_back({j,r[qt].num});
		// 		q[r[qt].toclub].push({val-b[r[qt].num][j],rtot});
		// 	}

			}
			else
				continue;
		}
		ans+=val;
		// cout<<"+"<<val<<endl;
		m[club]++;
		vis[num]=1;
		//add regret
		// c[num]=club;
		for(int j=0;j<3;j++)
			if(j!=club){
				rtot++;
				r.push_back({j,num});
				q[club].push({-val+b[num][j],rtot});
				q1[club].push(-val+b[num][j]);
			}
	}
		// for(int i=0;i<3;i++){
		// 	while(!q[i].empty()){
		// 		cout<<q[i].top().first<<" ";
		// 		q[i].pop();
		// 	}
		// 	cout<<endl;
		// }
	cout<<ans<<endl;
	// cout<<"*";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		slove();
	return 0;
}*/