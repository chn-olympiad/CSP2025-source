#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long a[105];
long long n,m,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int seat=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++) cout<<a[i];
	for(int i=0;i<n*m;i++)
		if(a[i]==seat){
			ans=i;
			break;
		}
	cout<<endl<<seat<<endl<<ans<<endl;
	printf("%d ",ans/n+1);
	if((ans/n+1)%2) printf("%d ",ans%n+1);
	else printf("%d ",n-(ans%n));
	return 0;
}
