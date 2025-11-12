#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		int a1[100005][5],a[100005]={0},s1[100005];
		int ans[5]={0},sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a1[i][j];
				if(a1[i][j]>a[i]){
					a[i]=a1[i][j];
					s1[i]=j;
				}
			}
			int f=0,s=0;
			for(int j=0;j<n;j++){
				if(a[j]>f){
					f=a[j];
					s=j;
				}
			}
			if(ans[s]+1<=n/2){
				ans[s]++;
				sum+=f;
			}
		}
		
		cout<<sum<<endl;
		t--;
	}
	return 0;
} 
