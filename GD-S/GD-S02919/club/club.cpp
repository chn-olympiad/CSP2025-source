//©\O2 ©\std=c++14 ©\static
//-std=c++14 -O2 -Wl,--stack=536870912
#include <bits/stdc++.h>
#define long long ll;
using namespace std;
const int N=1e5+5;
int a[N][3+5],cnt[3+5];
//int pos[N][3+5];
struct class_1{
	int v,name;
}vec[4][N+5];

bool cmp(const class_1 &x,const class_1 &y){
	return x.v>y.v;
}
/*
bool cmp2(const int &x,const int &y){
	return x>y;
}
*/

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>t;
	while(t--){
		set<int> name;
		int res=0;
		cin>>n;
		int full=n/2;
		//bool correct=false;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//cin>>b[i][1].v>>b[i][2].v>>b[i][3].v;
			//for(int j=1;j<=3;j++)vec[j].v.push_back(a[i][j]);
			for(int j=1;j<=3;j++){
				vec[j][i].v=a[i][j];
				vec[j][i].name=i;
			}
			//sort(a[i]+1,a[i]+3+1,cmp2);
			//sort(b[i]+1,b[i]+3+1,cmp);
		}
		for(int i=1;i<=3;i++)sort(vec[i]+1,vec[i]+n+1,cmp);
		
		if(vec[2][1].v==0&&vec[3][1].v==0){
			for(int i=1;i<=full;i++)res+=vec[1][i].v;
			cout<<res<<endl;
			//cout<<"test"<<endl;
			continue;
		}
		/*
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++)cout<<vec[i][j].v<<" ";
			cout<<endl;
		}
		*/
		int ans=0;
		
		for(int i=1;i<=3;i++){
			for(int j=1;j<=full;j++){
				if(name.count(vec[i][j].name)==0){
					ans+=vec[i][j].v;
					name.insert(vec[i][j].name);
				}
			}
			res=max(res,ans);
		}
		
		cout<<res<<endl;
	}
	return 0;
}
