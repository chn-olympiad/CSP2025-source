#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b;
int p[25];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)b=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=n;i++)p[n+i]=p[n-i+1];
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			cout<<(i-1)/n+1<<' ';
			int ans=(i-1)/n+1;
			if(i%n==1){
				if(ans%2==1){
					cout<<p[1];
				}else cout<<p[n];
			}else{
				cout<<(i-1)%n+1;
			}
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
