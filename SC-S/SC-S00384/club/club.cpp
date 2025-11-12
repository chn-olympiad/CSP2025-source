#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
long long T,n,a[N][3],ans,x,y,z;
priority_queue<int> n1,n2,n3;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		x=y=z=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++)
				cin>>a[i][j];
			if(a[i][0]>=max(a[i][1],a[i][2])){
				ans+=a[i][0];
				n1.push(max(a[i][1],a[i][2])-a[i][0]);
				x++;
			}	
			else if(a[i][1]>=max(a[i][0],a[i][2])){
				ans+=a[i][1];
				n2.push(max(a[i][0],a[i][2])-a[i][1]);
				y++;
			}
			else if(a[i][2]>=max(a[i][1],a[i][0])){
				ans+=a[i][2];
				n3.push(max(a[i][0],a[i][1])-a[i][2]);
				z++;
			}		
		}
		if(x>n/2)
			while(x>n/2){
				ans+=n1.top();
				n1.pop();
				x--;
			}
		if(y>n/2)
			while(y>n/2){
				ans+=n2.top();
				n2.pop();
				y--;
			}			
		if(z>n/2)
			while(z>n/2){
				ans+=n3.top();
				n3.pop();
				z--;
			}			
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}