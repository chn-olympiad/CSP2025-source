#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],sum1,x,t,sum2,y;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		bool flag=1;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i] >>x>>y;
			sum2+=max(a[i],max(x,y));
			if(x!=0) flag=0;
		} 
		sort(a+1,a+n+1,cmp);
		sum1=0;
		for(int j=1;j<=n/2;j++){
			sum1+=a[j];
		}
		if(flag) cout << sum1;
		else cout << sum2;
	}
	return 0;
}
