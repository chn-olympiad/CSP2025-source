#include<bits/stdc++.h>
using namespace std;
int t,n,s,o,w[3],u[3],a[3][500001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n,fill(w,w+3,0),s=a[0][0]=a[1][0]=a[2][0]=0;
		for(int i=0;i<n;i++){
			cin>>u[0]>>u[1]>>u[2];
			if(u[0]>u[1]&&u[0]>u[2]) o=0;
			else if(u[1]>u[0]&&u[1]>u[2]) o=1;
			else o=2;
			s+=u[o],a[o][++w[o]]=u[o]-max(u[(o+1)%3],u[(o+2)%3]);
		}
		for(o=0;o<3&&w[o]<=n/2;o++);
		if(o<3){
			sort(a[o]+1,a[o]+w[o]+1);
			for(int i=w[o]-n/2;i;i--) s-=a[o][i];
		}
		cout<<s<<endl;
	}
	return 0;
}
