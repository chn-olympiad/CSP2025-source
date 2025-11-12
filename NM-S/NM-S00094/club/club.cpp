#include<bits/stdc++.h>
using namespace std;
struct op{
	int a;
	int b;
	int c;
};
int t,n ,x[100010],y[100010],z[100010],a1[100010],b1[100010],c1[100010];
op q[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			for(int h=0;h<3;h++){
				if(max(q[i].a,q[i].b)==q[i].a&&max(q[i].a,q[i].c)==q[i].a){
				for(int j=0;j<n/2;j++){
					if(q[i].a>=x[j]){
						x[j]=q[i].a;
						a1[j]=i;
						break;
					}
					else if(j==n/2-1){
						q[i].a=-1;
					}
				}
			}
			if(max(q[i].a,q[i].b)==q[i].b&&max(q[i].b,q[i].c)==q[i].b){
				for(int j=0;j<n/2;j++){
					if(q[i].b>=y[j]){
						y[j]=q[i].b;
						b1[j]=i;
						break;
					}
					else if(j==n/2-1){
						q[i].b=-1;
					}
				}
			}
			if(max(q[i].a,q[i].c)==q[i].c&&max(q[i].b,q[i].c)==q[i].c){
				for(int j=0;j<n/2;j++){
					if(q[i].c>=z[j]){
						z[j]=q[i].c;
						c1[j]=i;
						break;
					}
					else if(j==n/2-1){
						q[i].c=-1;
					}
				}
			}
			}
			
		}
		int sum=0;
		for(int i=0;i<n/2;i++){
			sum+=q[a1[i]].a;
			sum+=q[b1[i]].b;
			sum+=q[c1[i]].c;
		}
		cout<<sum<<endl;
	}
	return 0;
}
