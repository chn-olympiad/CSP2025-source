#include<bits/stdc++.h>
using namespace std;
struct ins{
	int a;
	int b;
};
int bu[3];
ins d[3][100005];
ins d2[3][100005];
ins h[100005];
bool sor(ins x,ins y){
	if(x.a==y.a){
		return bu[x.b]<bu[y.b];
	}
	return x.a>y.a;
}
bool sor2(ins x,ins y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int he=0;
			for(int j=0;j<3;j++){
				cin>>d[j][i].a;
				d[j][i].b=j;
				bu[j]=0;
				d2[j][i].b=j;
				he+=d[j][i].a;
			}
			
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)
				h[j]=d[j][i];
			sort(h,h+3,sor);
			for(int j=0;j<3;j++){
				d[j][i]=h[j];
//				cout<<d[j][i].a<<" ";
			}
//			cout<<"\n";
		}
		for(int j=0;j<3;j++){
			for(int i=0;i<n;i++)
				h[i]=d[j][i];
			sort(h,h+n,sor);
			for(int i=0;i<n;i++){
				d[j][i]=h[i];
//				cout<<d[j][i].a<<" ";
			}
//			cout<<"\n";
		}
		
		int jie=0;
		for(int i=0;i<n;i++){
			int maxz=0;
			for(int j=0;j<3;j++){
				if(bu[d[j][i].b]>=n/2)continue;
//				cout<<d[j][i].b<<" "<<bu[d[maxz][i].b]<<"\n";
				if(d[j][i].a>d[maxz][i].a){
					maxz=j;
				}else if(d[j][i].a==d[maxz][i].a &&bu[d[j][i].b]<bu[d[maxz][i].b]){
					maxz=j;
				}else if(d[j][i].a==d[maxz][i].a &&bu[d[j][i].b]<bu[d[maxz][i].b]){
					maxz=j;
				}
			}
			if(bu[d[maxz][i].b]>=n/2)continue;
			bu[d[maxz][i].b]++;
			jie+=d[maxz][i].a;
//			for(int j=0;j<3;j++)
//				cout<<bu[d[j][i].b]<<" ";
		}
		cout<<jie<<"\n";
	}
	return 0;
}