#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long an=0;
int a[100010];
int b[100010];
int c[100010];
void dfs(int na,int nb,int nc,long long ai,int id){
	if(na*2>n||nb*2>n||nc*2>n||na+nb+nc>n){
		return;
	}
	if(id==n+1){
		an=max(an,ai);
		return ;
	}
	dfs(na+1,nb,nc,ai+a[id],id+1);
	dfs(na,nb+1,nc,ai+b[id],id+1);
	dfs(na,nb,nc+1,ai+c[id],id+1);
}
bool ae1(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		cin>>n;
		an=0;
		bool aa=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			aa=(aa&&(b[i]==0)&&(c[i]==0));
		}
		if(n<=30){
			dfs(0,0,0,0,1);
		}else if(aa){
			sort(a+1,a+1+n,ae1);
			for(int i=1;i<=n/2;i++){
				an+=a[i];
			}
		}else{
			for(int i=1;i<=n;i++){
				an+=max(a[i],max(b[i],c[i]));
			}
		}
		cout<<an<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
