#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,a[5005],iop=0,MAX=-1,lastMAX=-1;
map<vector<int>,bool>mp;
stack<int>ST;
bool b[5005];
bool cmp(int a,int b){
	return a<b;
}
void polyGON(int n){
	if(ST.size()>=3){
		if(iop>MAX*2){
			stack<int>St;
			vector<int>jkl;
			while(!ST.empty()){
				int av=ST.top();
				ST.pop();
				St.push(av);
				jkl.push_back(av);
			}
			int ui=jkl.size();
			for(int i=0;i<ui;i++){
				for(int j=0;j<ui;j++){
					if(jkl[i]<jkl[j])swap(jkl[i],jkl[j]);
				}
			}
			while(!St.empty()){
				ST.push(St.top());
				St.pop();
			}
			mp[jkl]=1;
		}
		return;
	}
	for(int i=n;i>=1;i--){
		if(b[i]==0){
			ST.push(a[i]);
			iop+=a[i];
			if(a[i]>MAX){
				lastMAX=MAX;
				MAX=a[i];
			}
			b[i]=1;
			polyGON(n-1);
			ST.pop();
			iop-=a[i];
			b[i]=0;
			MAX=lastMAX;
		}
	}
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		iop=0;
		MAX=-1;
		lastMAX=-1;
		polyGON(i);
	}
	cout<<mp.size()%N<<endl;
	return 0;
}
