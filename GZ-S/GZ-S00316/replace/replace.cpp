//GZ-S00316 毕节东辰实验学校 王子晨 
#include <bits/stdc++.h>
using namespace std;
int ans;
int n,q;
vector<vector<string> > rep(20001,vector<string>(3));
deque<string>  bfs;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	 
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		rep[i][1]=a;
		rep[i][2]=b;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string a,b;
		cin>>a>>b;
		bfs.push_back(a);
		while(!bfs.empty()){
			string c=bfs.front();
			for(int l=0;l<c.size();l++){
				string y="";
				for(int r=l;r<c.size();r++){
				 	y+=c[r];
					for(int j=1;j<=n;j++){
						if(y==rep[j][1]){
							int k=0;
							string x="";
							while(k<l){
								x+=c[k];
								k++;
							}
							x+=rep[j][2];
							k=r+1;
							while(k<c.size()){
								x+=c[k];
							}
							if(x==b){
								ans++;
							}
							bfs.push_back(x);
						}
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
