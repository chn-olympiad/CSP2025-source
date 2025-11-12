#include<bits/stdc++.h>
using namespace std;
int t,n,bj[100010];
long long ans;
struct node{
	int a,b,c,i;
}a[100010];
int cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].i=i;
			a[i].c=a[i].a;
		}
		sort(a,a+n,cmp);
		int i,j,cnt=0;
		for(i=0;i<n/2;i++){
			ans+=a[i].a;
			bj[a[i].i]=1;
		}
		sort(a,a+n,cmp);
		for(j=0;j<n&&cnt<n/2;j++){
			if(bj[a[j].i]!=1){
				ans+=a[j].b;
				cnt++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
