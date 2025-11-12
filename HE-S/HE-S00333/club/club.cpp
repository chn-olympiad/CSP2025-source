#include <iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[100000][3],b[100000],c[100000],n,t,q,max_a=0,x,y,z,num=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		x=n/2;y=n/2;z=n/2;
		for(int j=0;j<n;j++){
			for(int p=0;p<3;p++){
				cin>>a[j][p];
			}
		}
		for(int j=0;j<n;j++){
			for(int p=0;p<3;p++){
				if(a[j][p]>max_a){
					max_a=a[j][p];
					b[j]=p;
					q=p;
				}
				max_a=0;
			}
		}
		for(int j=0;j<n;j++){
			if(b[j]==0){
				if(x<0){
				for(int p=0;p<3;p++){
				    if(p==0){
				       	continue;
					}
					if(a[j][p]>max_a){
					    max_a=a[j][p];
				       b[j]=p;
			        }
			        max_a=0;
			    }
			}
				x--;
				num+=a[j][b[j]];
			}
			if(b[j]==1){
				if(y<0){
				for(int p=0;p<3;p++){
				    if(p==1){
				       	continue;
					}
					if(a[j][p]>max_a){
					    max_a=a[j][p];
				       b[j]=p;
			        }
			        max_a=0;
			    }
			}
				y--;
				num+=a[j][b[j]];
			}
			if(b[j]==2){
				if(z<0){
				for(int p=0;p<3;p++){
				    if(p==2){
				       	continue;
					}
					if(a[j][p]>max_a){
					    max_a=a[j][p];
				       b[j]=p;
			        }
			        max_a=0;
			    }
			}
				z--;
				num+=a[j][b[j]];
			}
		}
		c[i]=num;
		num=0;
	}
	bool first=true;
	for(int i=0;i<n;i++){
		if(first){
			cout<<c[i];
			first=false;
		}else{
		cout<<endl<<c[i];
		}
	}
}
