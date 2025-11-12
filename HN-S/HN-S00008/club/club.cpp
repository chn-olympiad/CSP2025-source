//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
	int d1,d2,d3;
	double id;
};
const int T=1e5+5;
node a[T];
long long n;
bool cmp(node c,node d){
	return c.d1>d.d1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long sum=0;
		int maxn=INT_MIN;
		cin>>n;
		bool ok=false;		
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			maxn=max(a[i].d1,a[i].d2);
			maxn=max(maxn,a[i].d3);	
			sum+=maxn;			
		}
		for(int i=1;i<=n;i++){
			if(a[i].d2==a[i].d3 && a[i].d2==0){
				ok=true;
			} 
			else{
				ok=false;break;
			}
		}
		if(ok==true) {
			sort(a+1,a+n+1,cmp);
			cout<<a[1].d1+a[2].d1<<'\n';continue;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
