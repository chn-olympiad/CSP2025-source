#include<iostream>
#include<algorithm> 
#include<vector> 
using namespace std;
const int N=1e5+10; 
int t,n;
struct member{
	int s[5];//满意度 
	int g[5]; 
};
member None;
vector<member> a;
void match(int pos){
	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=3;j++){
			if(a[pos].s[a[pos].g[i]]<a[pos].s[a[pos].g[j]]) swap(a[pos].g[i],a[pos].g[j]);
		}
	}
}
vector<member> mem[5];
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			a.push_back(None);
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			a[i].g[1]=1;
			a[i].g[2]=2;
			a[i].g[3]=3;
			match(i);
		}
		while(!a.empty()){
			for(int j=1;j<=3;j++){
				int x=a[0].g[j];//研究的部门 
				if(mem[x].size()<n/2){
					a[0].g[x]=0;
					match(0);
					mem[x].push_back(a[0]);
					sum+=a[0].s[x];
					a.erase(a.begin());
					break;
				}else if(mem[x][0].s[x]<a[0].s[x]&&mem[x][0].s[mem[x][0].g[1]]+a[0].s[x]>mem[x][0].s[x]+a[0].s[a[0].g[j+1]]){
					sum+=a[0].s[x]-mem[x][0].s[x];
					swap(mem[x][0],a[0]);
					break;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
		for(int i=1;i<=3;i++) mem[i].clear(); 
	}
	
} 
