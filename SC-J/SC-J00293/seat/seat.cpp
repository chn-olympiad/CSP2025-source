#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+m*n+1);
	int t;
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			t=m*n+1-i;
			break;
		}
	}
	int c=t/n;
	int s=t%n; 
	if(c%2==1&&s==0) cout<<c<<" "<<n;
	if(c%2==0&&s==0) cout<<c<<" "<<1;
	if(c%2==1&&s!=0) cout<<c+1<<" "<<n+1-s;
	if(c%2==0&&s!=0) cout<<c+1<<" "<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}