#include<iostream>
using namespace std;
struct student{
	int a,b,c;
} f[100005];
int n,am,bm,cm;
int t[100005],ans=-1;
void dfs(int x){
	if(x>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=t[i];
		}
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&am>0){
			t[x]=f[x].a;
			am--;
			dfs(x+1);
			am++;
		}else if(i==2&&bm>0){
			t[x]=f[x].b;
			bm--;
			dfs(x+1);
			bm++;
		}else if(i==3&&cm>0){
			t[x]=f[x].c;
			cm--;
			dfs(x+1);
			cm++;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=-1;
		am=bm=cm=n/2;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
} 
