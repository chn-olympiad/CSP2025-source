#include<bits/stdc++.h>
using namespace std;
int t,n,maxx[10010];
long long sum;
struct node{
	int one,two,three;
	int a1,a2,a3;
}a[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
			maxx[i]=max(max(a[i].one,a[i].two),a[i].three);
		}
		for(int i=1;i<=n;i++){
			sum+=maxx[i];
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
