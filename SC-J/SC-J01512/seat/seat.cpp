#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],total,t[1000][1000],h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	total=n*m;
	int ans=a[1];
	sort(a+1,a+1+total,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				t[i][j]=a[cnt];
				cnt++;
			}
			
		}
		else{
			for(int j=m;j>=1;j--){
				t[i][j]=a[cnt];
				cnt++;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(t[i][j]==ans)
				h=i,l=j;
	cout<<h<<" "<<l<<endl;
	return 0;
}