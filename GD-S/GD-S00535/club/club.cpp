#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int N1=N/2;
int t;
int n;
int a[N][4];
int a1,a2,a3;
bool cmp(int a,int b){
	return a>b;
}
void A(int x){
	int b[N];
	for(int i=1;i<=n;i++){
		b[i]=a[i][x];
	}
	sort(b+1,b+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=b[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]==0&&j==1)a1+=1;
				if(a[i][j]==0&&j==2)a2+=1;
				if(a[i][j]==0&&j==3)a3+=1;
			}
		}
		if(a1==n&&a2==n&&a3==n){
			cout<<0<<endl;
			continue;
		}
		if(a1==n&&a2==n){
			A(3);
			continue;
		}
		if(a1==n&&a3==n){
			A(2);
			continue;
		}
		if(a2==n&&a3==n){
			A(1);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
