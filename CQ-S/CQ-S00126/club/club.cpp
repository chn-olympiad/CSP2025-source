#include<bits/stdc++.h>
using namespace std;
int n,t,mx,sumx,sumy;
struct no{
	int x,y;
} a[100005];
bool cmp(no a,no b){
	return abs(a.x-a.y)<abs(b.x-b.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mx=-1e9;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].x>>a[i].y;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y){
				sumx++;
				mx+=a[i].x; 
			}
			else{
				sumy++;
				mx+=a[i].y; 
			}
		if(i==n)cout<<mx<<endl;
			else if(sumy==n/2){
				for(int j=i+1;j<=n;j++)mx+=a[i].x;
				cout<<mx<<endl;
				break;
			}
			
			else if(sumx==n/2){
				for(int j=i+1;j<=n;j++)mx+=a[i].y;
				cout<<mx<<endl;
			}
		}
	}
	return 0;
}
