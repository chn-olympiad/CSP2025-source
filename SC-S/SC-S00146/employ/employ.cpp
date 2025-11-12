#include<iostream>
#include<vector>
using namespace std;
int c[1000];
string s;
int n,m,ans;
bool vis[1000];
void f(int d,int p,int g){
	if(d==n){
		if(p>=m){
			ans++;
			//cout<<l<<" "<<p<<"\n";
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			int P=p,G=g;
			vis[i]=1;
			if(g<c[i]&&s[d]=='1')P++;
			else G++;
			f(d+1,P,G);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	f(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}