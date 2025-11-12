#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t;
int n;
long long ans;

struct a{
	int d1;
	int d2;
	int d3;
}a[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
				ans+=a[i].d1;
			}else if(a[i].d2>=a[i].d1&&a[i].d2>=a[i].d3){
				ans+=a[i].d2;
			}else{
				ans+=a[i].d3;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
