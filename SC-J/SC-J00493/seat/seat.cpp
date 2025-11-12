#include<iostream>
#include<cstdio>
using namespace std;
bool vis[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	int a[150];a[0]=-1145114;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		int Max=0;
		for(int j=1;j<=n*m;j++){
			if(a[j]>a[Max] && (!vis[j])){
				Max=j;
			}
		}
		vis[Max]=1;
		if(Max==1){
			l=i;
			break;
		}
	}
	int j=(l-1)/n+1,i;
	i=(j%2==0)? n-(l-1)%n : (l-1)%n+1;
	cout<<j<<" "<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
