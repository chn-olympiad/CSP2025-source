#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string a[N],b[N];
string q1,q2;
int n,q,ans;
bool v[N];
int sum=0;
void dfs(string now){
//	cout<<now<<endl;
//	cout<<"p";
//	cout<<a[1][0]<<" "<<now[0]<<endl;
//	if(now==q2){
//	//	cout<<"p";
//		ans++;return;
//	}
	if(sum)return;
	for(int i=1; i<=n; i++){
		int k=0;
		for(int j=0; j<now.size(); j++){
			int j2=j;
			while(a[i][k]==now[j2]&&k<a[i].size()&&j2<now.size()){
				k++,j2++;
			}
		//	cout<<k<<" "<<i<<endl;
				if(k==a[i].size()){
				//	cout<<"i="<<i<<endl;
					string now2;
					for(int p=j; p<j+a[i].size(); p++)now2[p]=now[p],now[p]=b[i][p-j];
					if(now==q2)ans++;
//					sum++;
//					dfs(now);
					for(int p=j; p<j+a[i].size(); p++)now[p]=now2[p];
				//	sum--;
					k=0;
				}
		
		}
		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0,sum=0;
		cin>>q1>>q2;
	//	cout<<q1<<endl;
		dfs(q1);
		cout<<ans<<'\n';
	}
} 
