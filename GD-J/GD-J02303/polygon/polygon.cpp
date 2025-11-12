#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
bool cmp(int x,int y){
	return x>y;
}
int a[5005],n,k=0,b[5005];
void u(){
	for (int i=1;i<=n;i++)b[i]=0;
}
void dfs(int l){
	if (l<3){
		for (int i=b[l]+1;i<=n;i++){
			b[l+1]=i;
			dfs(l+1);
			return ;
		}
	}
	int x=0;
	for (int i=2;i<=l;i++){
		x+=a[b[i]];
	}
	
	if (l==n&&x>a[b[1]]){
		for (int i=1;i<=l;i++)cout<<a[b[i]]<<' ';
		
		k++;
		cout<<k;
		cout<<endl;
		return ;
	}else if(l==n&&x<a[b[1]]){
		return ;
	}
	
	if (x>a[b[1]]){
		k++;
		for (int i=1;i<=l;i++)cout<<a[b[i]]<<' ';
		cout<<k;
		cout<<endl;
		for (int i=b[l]+1;i<=n;i++){
			b[l+1]=i;
			dfs(l+1);
		}
		return ;
	}else{
		for (int i=b[l]+1;i<=n;i++){
			b[l+1]=i;
			dfs(l+1);
		}
		return ;
	}
} 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n-1;i++){
		b[1]=i;
		dfs(1);
	}
	cout<<k;
}
