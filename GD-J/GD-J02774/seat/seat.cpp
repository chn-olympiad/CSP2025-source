#include<bits/stdc++.h>
using namespace std;
int n,m,v[20][20],a[105],s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	int flag=0,z=n*m,h=1,l=1;
	sort(a+1,a+1+n*m);
	while(z>0){
		if(h==1&z!=n*m){
			v[h][l]=a[z];
			l++,z--,flag=0;
			if(z>0){
			v[h][l]=a[z];
			h++,z--;
			continue;
			}
		} 
		if(h==m){
			v[h][l]=a[z];
			l++,z--,flag=1;
			if(z>0){
			v[h][l]=a[z];
			h--,z--;
			continue;
			}
		}
		v[h][l]=a[z];
		if(flag==0) h++;
		else h--;
		z--;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<v[i][j]<<" ";
//				
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==s){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}


