#include<bits/stdc++.h>
using namespace std;
int a[10005][4],b[4],c;
int main(){
	freopen("club.in","r",stdin);
	freoprn("club.out","w",stdout);
	int t,n,t1=-1,t2=-1,t3=114514;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int c=0;
		for(int j=1;j<=n;j++){
			int l=0,o=0,p=0,t1=-1,t2=-1,t3=114514;
			for(int d=1;d<=3;d++){
				cin>>a[j][d];
				if(a[j][d]>t1){
					t1=a[j][d];
					l=d;
				}
			}
			c+=t1;
			b[l]++;
			if(b[l]>n/2){
				for(int f=1;f<=3;f++){
					if(a[j][f]==t1){
						continue;
					}
					if(a[j][f]>t2){
						t2=a[j][f];
						o=f;
					}
					if(a[j][f]<t3){
						t3=a[j][f];
						p=f;
					}
				}
				b[l]--;
				c-=t1;
				b[o]++;
				c+=t2;
				if(b[o]>n/2){
					b[o]--;
					c-=t2;
					b[p]++;
					c+=t3;
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
