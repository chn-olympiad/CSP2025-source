#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e3+10;
int n,m,tot=1;
ll aans=0;
string s;
int v[MAXN];
int a[MAXN];
vector<int> ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		tot*=i;
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		ans.push_back(i);
	}
	int lst=0,cnt=0;
	for(int i=1;i<=tot;i++){
		cnt=0;
		lst=0;
		
//		for(int i=0;i<ans.size();i++) cout<<ans[i];
//		cout<<endl;
		for(int i=0;i<ans.size();i++){
			if(s[i]=='1'&&lst<=v[ans[i]]){
				cnt++;
			}else{
				lst++;
			}
		}
		if(m<=cnt){
			aans++;
		}
		next_permutation(ans.begin(),ans.end());
	}
	cout<<aans<<endl;
}
