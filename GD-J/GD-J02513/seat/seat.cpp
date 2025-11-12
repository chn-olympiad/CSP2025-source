#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int num[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>num[i*n+j];
	int ans=num[1];
	sort(num+1,num+1+n*m,cmp);
	int find;
	for(int i=1;i<=n*m;i+=n){
		if(num[i]>=ans && num[i+n-1]<=ans){
			for(int j=1;j<=i+n-1;j++){
				if(num[j]==ans){
					find=j;
					break;
				}
			}
			break;
		}
	}
	if(find%n==0){
		cout<<find/n<<" "<<n;
		return 0;
	}
	int ans2=find/n+1;
	cout<<ans2<<" ";
	int ans3=find%n;
	if(find/n%2==1)
		cout<<m-ans3+1;
	else
		cout<<ans3;
	return 0;
} 

