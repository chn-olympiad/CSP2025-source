#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+7;
struct Node{
	int del,id;
} x[N];
bool cmp(Node a,Node b){
	return a.del<b.del;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int a1,a2,a3;
		ll ans=0;
		int c[4];
		c[1]=c[2]=c[3]=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			if(a1 >=a2 && a1>=a3){
				c[1]++;
				x[i].id=1;
				if(a2>=a3) x[i].del=a1-a2;
				else x[i].del=a1-a3;
			}
			else if(a2>=a1 && a2 >=a3){
				c[2]++;
				x[i].id=2;
				if(a1>=a3) x[i].del=a2-a1;
				else x[i].del=a2-a3;
			}else{
				c[3]++;
				x[i].id=3;
				if(a1>=a2) x[i].del=a3-a1;
				else x[i].del=a3-a2;
			}
			ans+=max(a1,max(a2,a3));
		}
		if(c[1]<=n/2 && c[2]<=n/2 &&c[3]<=n/2){
			cout << ans << endl;
			continue;
		}
		sort(x,x+n,cmp);
		int cx;
		if(c[1]>n/2) cx=1;
		else if(c[2]>n/2) cx=2;
		else cx=3;
		for(int i=0;i<n;i++){
			if(x[i].id==cx){
				ans-=x[i].del;
				c[cx]--;
			}
			if(c[cx]<=n/2) break;
		}
		cout << ans << endl;
	}
	return 0;
}
