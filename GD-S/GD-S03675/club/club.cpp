#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans=0;
struct node{
	int x,y,z;
};
node a[5][100005];
int c1=0,c2=0,c3=0;
int c=0;
void f1(){
	for(int i=0;i<c1;i++){
		ans+=a[1][i].x;
	//	cout<<a[1][i].x<<" ";
	}
//	cout<<endl;
	for(int i=0;i<c2;i++){
		ans+=a[2][i].y;
	//	cout<<a[2][i].y<<" ";
	}
	//cout<<endl;
	for(int i=0;i<c3;i++){
		ans+=a[3][i].z;
	//	cout<<a[3][i].z<<" ";
	}
//	cout<<endl;
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		for(int i=1;i<=n;i++){
			int fi,se,tr;
			cin>>fi>>se>>tr;
			if(fi>=se&&fi>=tr){
				a[1][c1].x=fi;
				a[1][c1].y=se;
				a[1][c1].z=tr;
				c1++;
			}
			else if(se>=fi&&se>=tr){
				a[2][c2].x=fi;
				a[2][c2].y=se;
				a[2][c2].z=tr;
				c2++;
			}
			else{
				a[3][c3].x=fi;
				a[3][c3].y=se;
				a[3][c3].z=tr;
				c3++;
			}
		}
		if(c1>n/2) c=1;
		if(c2>n/2) c=2;
		if(c3>n/2) c=3;
	//	cout<<c<<endl;
		if(c==0){
			f1();
		}
		else if(c==1){
			for(int i=1;i<=(c1-n/2);i++){
				int minc=100000000,v;
				for(int j=0;j<c1;j++){
					if(a[1][j].x!=0&&a[1][j].x-max(a[1][j].y,a[1][j].z)<minc){
						minc=a[1][j].x-max(a[1][j].y,a[1][j].z);
						v=j;
					}
				}
				//cout<<v;
				a[1][v].x=0;
				if(a[1][v].y>=a[1][v].z){
					a[2][c2].y=a[1][v].y;
					c2++;
				}
				else{
					a[3][c3].z=a[1][v].z;
					c3++;
				}
			}
		f1();	
		}	
		else if(c==2){
			for(int i=1;i<=(c2-n/2);i++){
				int minc=100000000,v;
				for(int j=0;j<c2;j++){
					if(a[2][j].y!=0&&a[2][j].y-max(a[2][j].x,a[2][j].z)<minc){
						minc=a[2][j].y-max(a[2][j].x,a[2][j].z);
						v=j;
					}
				}
				//cout<<v;
				a[2][v].y=0;
				if(a[2][v].x>=a[2][v].z){
					a[1][c1].x=a[2][v].x;
					c1++;
				}
				else{
					a[3][c3].z=a[2][v].z;
					c3++;
				}
			}
		f1();	
		}
		else if(c==3){
			for(int i=1;i<=(c3-n/2);i++){
				int minc=100000000,v;
				for(int j=0;j<c3;j++){
					if(a[3][j].z!=0&&a[3][j].z-max(a[3][j].y,a[3][j].x)<minc){
						minc=a[3][j].z-max(a[3][j].y,a[3][j].x);
						v=j;
					}
				}
				//cout<<v;
				a[3][v].z=0;
				if(a[3][v].x>=a[3][v].y){
					a[1][c1].x=a[3][v].x;
					c1++;
				}
				else{
					a[2][c2].y=a[3][v].y;
					c2++;
				}
			}
		f1();	
		}
		memset(a,0,sizeof(a));
		c1=c2=c3=c=ans=0;
	}
	return 0;
}
