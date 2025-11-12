#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int num,k;
}a[N][4];
int t;
int n,b[4];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		bool f=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].k=j;
			}
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+1+n,cmp);
		}
		for(int i=1;i<=n;i++){
			if(b[a[i][1].k]+1>n/2&&f==0){
				if(b[a[i][2].k]+1<=n/2&&f==0) ans+=a[i][2].num,b[a[i][2].k]++;
				else if(b[a[i][2].k]+1>n/2&&f==0){
					if(b[a[i][3].k]+1<=n/2&&f==0) ans+=a[i][3].num,b[a[i][3].k]++;
					else if(b[a[i][3].k]+1>n/2&&f==0){
						f=1;
						break;	
					}
				}
			}
			else if(b[a[i][1].k]+1<=n/2&&f==0) ans+=a[i][1].num,b[a[i][1].k]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
