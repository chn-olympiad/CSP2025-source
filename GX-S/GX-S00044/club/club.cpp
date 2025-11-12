#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n[6],a[3],b[6][3],ans[6],sum0[6],sum1[6],sum2[6];
struct node{
	int d1,d2;
}s[N];
bool cmp(node a,node b){
	return a.d2>b.d2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		int m=n[i]/2;
		for(int j=1;j<=n[i];j++){
			cin>>a[0]>>a[1]>>a[2];
			b[i][0]=a[0],b[i][1]=a[1],b[i][2]=a[2];
			sort(a,a+3);
			ans[i]=ans[i]+a[2];
			if(a[2]==b[i][0])sum0[i]++;
			else if(a[2]==b[i][1])sum1[i]++;
			else sum2[i]++;
			s[j].d1=a[2];
			s[j].d2=a[1];
		}
		sort(s+1,s+n[i]+1,cmp);
		if(sum0[i]>m){
			int h=sum0[i]-m;
			for(int j=1;j<=h;j++)ans[i]=ans[i]-s[j].d1+s[j].d2;
		}
		if(sum1[i]>m){
			int h=sum1[i]-m;
			for(int j=1;j<=h;j++)ans[i]=ans[i]-s[j].d1+s[j].d2;
		}
		if(sum2[i]>m){
			int h=sum2[i]-m;
			for(int j=1;j<=h;j++)ans[i]=ans[i]-s[j].d1+s[j].d2;
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}
/*
 * 
*/
