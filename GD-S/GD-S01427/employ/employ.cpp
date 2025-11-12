#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int P=998244353;
int n,m,ans;
int c[N];
string s;
bool r[N],isall;

void dfs(vector<int> v){
	if(v.size()==n){
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'||sum>=v[i]){
				sum++;
			}
		} 
		if(n-sum>=m){
			
//			for(int i=0;i<v.size();i++){
//				cout<<v[i]<<" ";
//			}
//			cout<<endl;
			
			ans++;
			ans%=P;
			return;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(!r[i]){
			v.push_back(c[i]);
			r[i]=true;
			dfs(v);
			r[i]=false;
			v.pop_back();
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			isall=true;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			isall=true;
		}
	}
	if(!isall){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%P;
		}
		cout<<ans%P<<endl;
		return 0;
	}
	dfs({});
	cout<<ans%P<<endl;
	return 0;
} 
