#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt=0;
struct stu{
	int a[5],x,y,z;
}az[100005];
bool pd=0;
bool cmp1(stu x,stu y){
	if(x.a[1]==y.a[1]){
		return x.a[2]<=y.a[2];
	}
	return x.a>=y.a;
}
bool cmp2(stu x,stu y){
	if(x.a[x.x]==y.a[y.x]){
		if(x.a[x.y]==y.a[x.y]){
			return x.a[x.z]>x.a[x.z];
		}
		else{
			return x.a[x.y]<x.a[x.y];
		}
	}
	return x.a[x.x]>x.a[x.x];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t--;){
		cin>>n;
		int x=0,y=0,z=0;
		pd=0;cnt=0;
		for(int i=1;i<=n;i++){
			cin>>az[i].a[1]>>az[i].a[2]>>az[i].a[3];
			if(az[i].a[1]>=az[i].a[2]&&az[i].a[2]>=az[i].a[3]){
				az[i].x=1;
				az[i].y=2;
				az[i].z=3;
			}
			else if(az[i].a[1]>=az[i].a[3]&&az[i].a[3]>=az[i].a[2]){
				az[i].x=1;
				az[i].y=3;
				az[i].z=2;
			}
			else if(az[i].a[2]>=az[i].a[1]&&az[i].a[1]>=az[i].a[3]){
				az[i].x=2;
				az[i].y=1;
				az[i].z=3;
			}
			else if(az[i].a[2]>=az[i].a[3]&&az[i].a[3]>=az[i].a[1]){
				az[i].x=2;
				az[i].y=3;
				az[i].z=1;
			}
			else if(az[i].a[3]>=az[i].a[1]&&az[i].a[1]>=az[i].a[2]){
				az[i].x=3;
				az[i].y=1;
				az[i].z=2;
			}
			else{
				az[i].x=3;
				az[i].y=2;
				az[i].z=1;
			}
			if(az[i].a[3]!=0)pd=1;
		}
		if(!pd){
			sort(az+1,az+1+n,cmp1);
			for(int i=1;i*2<=n;i++){
				cnt+=az[i].a[1];
			}
			for(int i=n;i*2>n;i--){
				cnt+=az[i].a[2];
			}
			cout<<cnt<<"\n";
		}
		else{
			int qc[5]={0,0,0,0};
			sort(az+1,az+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(qc[az[i].x]<n/2){
					cnt+=az[i].a[az[i].x];
					qc[az[i].x]++;
				}
				else if(qc[az[i].y]<n/2){
					cnt+=az[i].a[az[i].y];
					qc[az[i].x]++;
				}
				else {
					cnt+=az[i].a[az[i].z];
					qc[az[i].z]++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
