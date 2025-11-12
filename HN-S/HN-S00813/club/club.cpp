#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[100005][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				a[i][j]=0;
			}
		}
		cin>>n;
		int m=0,x=0,y=0,z=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=n;i>=0;i--){
			if(x>=n/2&&y>=n/2&&z>=n/2) m+=0;
			else if(x>=n/2&&y>=n/2){
				m+=a[i][2];
				z++;
			}
			else if(x>=n/2&&z>=n/2){
				m+=a[i][1];
				y++;
			}
			else if(y>=n/2&&z>=n/2){
				m+=a[i][0];
				x++;
			}
			else if(x>=n/2){
				m+=max(a[i][1],a[i][2]);
				if(a[i][1]>a[i][2]) y++;
				else z++;
			}
			else if(y>=n/2){
				m+=max(a[i][0],a[i][2]);
				if(a[i][0]>a[i][2]) x++;
				else z++;
			}
			else if(z>=n/2){
				m+=max(a[i][0],a[i][1]);
				if(a[i][0]>a[i][2]) x++;
				else y++;
			}
			else{
				m+=max(a[i][0],max(a[i][1],a[i][2]));
				if(a[i][1]>a[i][2]&&a[i][1]>a[i][0]) y++;
				else if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]) x++;
				else if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]) z++;
			}
		}
		cout<<m<<endl;
	}
	return 0;
} 
