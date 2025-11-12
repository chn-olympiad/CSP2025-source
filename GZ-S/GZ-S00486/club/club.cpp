//GY-S40086 贵阳市第一中学 陶昱泽
#include<bits/stdc++.h>
using namespace std;
int a[100001][6],b[4],ans ;
int t,n,z,e;
bool c;
void zhao(int y){
	for(int i=1;i<z;i++){
		if(a[i][4]==y){
			if(a[e][0]>a[i][0]){
				e=i;
				return;
			}
		}
	}
	c=0;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int d=n/2;
		for(int i=1;i<=d;i++){
			int maxa=1,mid=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			for(int j=2;j<=3;j++){
				if(a[i][j]>a[i][maxa]){
					maxa=j;
				}
			}
			for(int j=2;j<=3;j++){
				if(j!=maxa){
					if(mid==0||a[i][j]>a[i][mid]){
						mid=j;
					}
				}
			}
			a[i][0]=a[i][maxa]-a[i][mid];
			a[i][4]=maxa;
			a[i][5]=mid;
			b[maxa]++;
		}
		for(z=d+1;z<=n;z++){
			int maxa=1,mid=0;
			cin>>a[z][1]>>a[z][2]>>a[z][3];
			for(int j=2;j<=3;j++){
				if(a[z][j]>a[z][maxa]){
					maxa=j;
				}
			}
			for(int j=2;j<=3;j++){
				if(j!=maxa){
					if(mid==0||a[z][j]>a[z][mid]){
						mid=j;
					}
				}
			}
			a[z][0]=a[z][maxa]-a[z][mid];
			a[z][4]=maxa;
			a[z][5]=mid;
			if(b[maxa]>=d){
				c=1;
				e=z;
				while(c){
					zhao(maxa);
				}
				swap(a[e][4],a[e][5]);
			}else{
				b[maxa]++;
			}	
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][4]];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
