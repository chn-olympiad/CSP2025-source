#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,k;
	long m;
	cin>>n>>m>>k;
	int a[n+k][n+k];
	int o[k];
	int past[n+k];
	memset(a,0,sizeof(a));
	for(int i=1;i<=n+k;i++){
		int num1,num2;
		if(i>n){
			cin>>o[i];
			for(int j=1;j<=n;j++){
				cin>>a[j][i];
				a[i][j]=a[j][i];
				
			}
			continue;
		}
		cin>>num1>>num2;
		cin>>a[num1][num2];
		a[num2][num1]=a[num1][num2];
	}
	int min,ans=0,cnt=0,i=1;
	while(cnt<n){
		min=1;
		for(int j=1;j<=n+k;j++){
			if(a[i][j]==0 ) {
				min++;
				continue;
			}
			else if(past[j]==1){
				min++;
				continue;
			}
			else if(j>n && a[i][j]+o[j]<a[i][min]){
				min=j;
				continue;
			}
			else if(a[i][j]<a[i][min]) min=j;
		}
		if(min>n){
			ans+=a[i][min]+o[min];
		}
		else{
			ans+=a[i][min];
		}
		past[i]=1;
		i=min;
		cnt++;
	}
	cout<<ans+1;
	return 0;
}


