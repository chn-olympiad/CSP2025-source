#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,out=0;
	cin>>n>>m;
	string s;
	cin>>s;
	int vis[505]={0};
	vector<int> a;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		vis[x]++;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int sum=1,j=0;
	for(int i=0;i<a.size();i++){
		sum*=vis[a[i]];
		if(a[i]<=out){
			out++;
			continue;
		}
		if(s[j]=='1'){
			vis[a[i]]=1;
		}
		else{
			out++;
		}
		j++;
	}
	cout<<sum;
	return 0;
}
