#include<bits/stdc++.h>
#define ll long long;
using namespace std;
map<string,string > ma; 
string x,y;
int ans;
void f(int q,int p){
	string s1,s2;
	for(int i=q;i<=p;i++){
		s1=s1+x[i];
		s2=s2+y[i];
	}
	if(ma[s1]==s2) ans++;
	if(q==0&&p==x.size()-1){
		return ;	
	}
	if(q==0){
		f(q,p+1);
		return ;
	}
	if(p==x.size()-1){
		f(q-1,p);
		return ;
	}
	f(q-1,p);
	f(q,p+1);
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		ma[x]=y;
		ma[y]=x;
	}
	for(int o=1;o<=m;o++){
		cin>>x>>y;
		if(x.size()!=y.size()||x==y){
			cout<<0<<"\n";
			continue;
		}
		int q=x.size();
		int i=0;
		int flag=0,cnt=0;
		int x1,x2;
		while(i<q){
			if(x[i]!=y[i]){
				if(flag){
					cnt=1;
					break;
				}
			}
			int j=i+1;
			while(j<q){
				if(x[j]==y[j]){
					x1=i;
					x2=j-1;
					flag=1;
					break;
				}
				j++;
			}
			if(!flag){
				x1=i;
				x2=q-1;
				flag=1;
			}
			i++;
		}
		f(x1,x2);	
		cout<<ans<<"\n";
		ans=0;	
	}
	return 0;
}