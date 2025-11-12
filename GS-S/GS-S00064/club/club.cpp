#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+5;
int a[N],b[N],c[N];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,maxn;
		cin>>n;
		maxn=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int sum1=0;
		int sum2=0;
		int sum3=0;
		for(int i=1;i<=maxn;i++){
			sum1+=a[i];
			sum2+=b[i];
			sum3+=c[i];
		}
		cout<<max(sum1,max(sum2,sum3));
	}
	return 0;
}
