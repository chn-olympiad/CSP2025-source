#include<bits/stdc++.h>
using namespace std;

int t,n,k=1;
long long a[100050][4];
int f[10];
long long m[10];

void bfs(int arr,long long ans){
	if(arr>n){
		m[k]=max(m[k],ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(f[i]>=n/2){
			continue;
		}
		f[i]++;
		bfs(arr+1,ans+a[arr][i]);
		f[i]--;
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		n=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		bfs(1,0);
		k++;
	}
	for(int i=1;i<k-1;i++){
		cout<<m[i]<<endl;
	}
	cout<<m[k-1];
	
	return 0;
}
