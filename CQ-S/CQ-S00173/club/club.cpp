#include<bits/stdc++.h> 
using namespace std;
int n,m; 
int a[20005],b[20005],c[20005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x=0,y=0,z=0,cnt=0;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+m);
		sort(b+1,b+1+m);
		sort(c+1,c+1+m);
		for(int i=1;i<=m;i++){
			if(a[i]>=b[i] && a[i]>=c[i]){
				if(x<m/2){
					x++;
					cnt+=a[i];
				}
				else {
					if(b[i]>=c[i]){
						y++;
						cnt+=b[i];
					}
					else {
						z++;
						cnt+=c[i];
					}
				}
			}
			else if(b[i]>=a[i] && b[i]>=c[i]){
				if(y<m/2){
					y++;
					cnt+=b[i];
				}
				else{
					if(a[i]>=c[i]){
						x++;
						cnt+=a[i];
					}
					else {
						z++;
						cnt+=c[i];
					}
				}
			}
			else if(a[i]>=a[i] && c[i]>=b[i]){
				if(z<m/2){
					z++;
					cnt+=c[i];
				}
				else{
					if(a[i]>=b[i]){
						x++;
						cnt+=a[i];
					}
					else {
						y++;
						cnt+=b[i];
					}
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=1;i<=m+1;i++){
			a[i]=0,b[i]=0,c[i]=0;
		}
	}
	return 0;
}
