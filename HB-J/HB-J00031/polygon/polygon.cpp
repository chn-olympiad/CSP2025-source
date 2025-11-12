#include<bits/stdc++.h>
using namespace std;
int i,n,a[5005],m,head,tail;
long long ans,fix;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)cout<<a[i];
	for(m=3;m<=n;m++){
		head=1,tail=1,fix=a[head];
		for(i=1;i<n;i++){
		tail++;
		fix+=a[tail];
		if(tail-head==m-1){
			if(fix>a[tail]*2){
			}
			fix-=a[head];
			head++;
		}
		}
	}
	cout<<(ans*2-1)%998244353;
	return 0;
}
