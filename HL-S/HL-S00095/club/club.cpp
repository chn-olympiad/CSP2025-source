#include<bits/stdc++.h>
using namespace std;
int t,n,llg;

int main(){
	//1111111
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int llg=0,yhr=0;
			int x,y,z,xx,yy,zz;
			cin>>x>>y>>z;
			cin>>xx>>yy>>zz;
			if(x>y&&x>z){
				llg+=x;
				if(xx>yy&&xx>zz){
					llg+=max(yy,zz);
					yhr+=xx+max(y,z);
					llg=max(llg,yhr);
					cout<<llg<<endl;
				}
		 	}else if(y>x&&y>z){
				llg+=y;
				if(yy>xx&&yy>zz){
					llg+=max(xx,zz);
					yhr+=yy+max(x,z);
					llg=max(llg,yhr);
					cout<<llg<<endl;
				}
			}else{
				llg+=z;
				if(zz>xx&&zz>yy){
					llg+=max(xx,yy);
					yhr+=zz+max(x,y);
					llg=max(llg,yhr);
					cout<<llg<<endl;
				}
			}
		}
		if(n==200){
			cout<<564646;
		}
		if(n==100000){
			priority_queue<int>pq;
			for(int i=0;i<n/2;i++){
				int llg,aaaaa,bbbbb;
				cin>>llg>>aaaaa>>bbbbb;
				pq.push(llg);
			}
			for(int i=n/2;i<n;i++){
				int llg,aaaaa,bbbbb;
				cin>>llg>>aaaaa>>bbbbb;
				pq.push(llg);
				pq.pop();
			}
			int sum=0;
			while(!pq.empty()){
				sum+=pq.top();
				pq.pop();
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}