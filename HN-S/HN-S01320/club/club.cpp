#include<iostream>
#include<cstring>
#include<vector>>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
	int w,id;
	bool operator<(const node &n0)const{
		return w>n0.w;
	}
};
int t,n;
node a[N][5];
vector<int> v[5];
bool cmp(int i,int j){
	return a[i][1].w!=a[j][1].w?a[i][1].w>a[j][1].w:a[i][2].w>a[j][2].w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof a);
		v[1].clear();
		v[2].clear();
		v[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[i][1]={a1,1};
			a[i][2]={a2,2};
			a[i][3]={a3,3};
			sort(a[i]+1,a[i]+4);
		}
		int cnt[5]={0,0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			cnt[a[i][1].id]++;
			v[a[i][1].id].push_back(i);
			ans+=a[i][1].w;
		}
		int num=0;
		if(cnt[1]>n/2)num=1;
		if(cnt[2]>n/2)num=2;
		if(cnt[3]>n/2)num=3;
		if(num==0){
			cout<<ans<<endl;
			continue;
		}
		int sum=0,res=0;
		sort(v[num].begin(),v[num].end(),cmp);
		for(int i=0;i<v[num].size();i++){
			res+=a[i][1].w;
			if(i<n/2)sum+=a[i][2].w;
			else sum+=a[i][1].w;
		}
		ans=ans-res+sum;
		cout<<ans-1<<endl;
	}
	return 0;
}
