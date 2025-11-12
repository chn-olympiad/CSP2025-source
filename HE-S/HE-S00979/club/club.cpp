#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		int n;
		cin>>n;
		int a1[100005][5],a[100005]={0},s[100005],s1[100005];
		int ans[5]={0},sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a1[i][j];
				if(a1[i][j]>a[i]){
					a[i]=a1[i][j];
					s1[i]=j;
				}
			}
			s[i]=a[i];
			if(ans[s1[i]]+1<=n/2){
				ans[s1[i]]++;
				sum+=s[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
