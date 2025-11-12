#include <bits/stdc++.h>
using namespace std;
int cl[3],cl1[3];
int maxn[100001],maxn1[100001];
struct node{
	int x,y,z,bi;
}a[100001];
bool cmp1(node s,node d){
	return s.x<d.x;
}
bool cmp2(node s,node d){
	return s.y<d.y;
}
bool cmp3(node s,node d){
	return s.z<d.z;
}
bool cmp4(node s,node d){
	return s.bi<d.bi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cl[0]=0;
		cl[1]=0;
		cl[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].bi=i;
			maxn[i]=max(a[i].x,max(a[i].y,a[i].z));
			maxn1[i]=max(a[i].x,max(a[i].y,a[i].z));
			if(maxn[i]==a[i].x){
				cl[0]++;
				cl1[0]++;
			}else if(maxn[i]==a[i].y){
				cl[1]++;
				cl1[1]++;
			}else{
				cl[2]++;
				cl1[2]++;
			}
		}
		if(cl[0]>(n/2)){
			int clj=cl[0];
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=(clj-(n/2));i++){
				if(a[i].y>=a[i].z){
					cl[0]--;
					cl[1]++;
					maxn[a[i].bi]=a[i].y;
				}else{
					cl[0]--;
					cl[2]++;
					maxn[a[i].bi]=a[i].z;
				}
			}
			for(int i=n;i>=(clj-(n/2))+1;i--){
				if(a[i].y>=a[i].z){
					cl1[0]--;
					cl1[1]++;
					maxn1[a[i].bi]=a[i].y;
				}else{
					cl1[0]--;
					cl1[2]++;
					maxn1[a[i].bi]=a[i].z;
				}
			}
		}
		if(cl[1]>(n/2)){
			int clj=cl[1];
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=(clj-(n/2));i++){
				if(a[i].x>=a[i].z){
					cl[1]--;
					cl[0]++;
					maxn[a[i].bi]=a[i].x;
				}
				else{
					cl[1]--;
					cl[2]++;
					maxn[a[i].bi]=a[i].z;
				}
			}
			for(int i=n;i>=(clj-(n/2))+1;i--){
				if(a[i].x>=a[i].z){
					cl1[1]--;
					cl1[0]++;
					maxn1[a[i].bi]=a[i].x;
				}else{
					cl1[1]--;
					cl1[2]++;
					maxn1[a[i].bi]=a[i].z;
				}
			}
		}
		if(cl[2]>(n/2)){
			int clj=cl[2];
			sort(a+1,a+1+n,cmp3);
			for(int i=1;i<=(clj-(n/2));i++){
				if(a[i].x>=a[i].y){
					cl[2]--;
					cl[0]++;
					maxn[a[i].bi]=a[i].x;
				}else{
					cl[2]--;
					cl[1]++;
					maxn[a[i].bi]=a[i].y;
				}
			}
			for(int i=n;i>=(clj-(n/2))+1;i--){
				if(a[i].x>=a[i].y){
					cl1[2]--;
					cl1[0]++;
					maxn1[a[i].bi]=a[i].x;
				}else{
					cl1[2]--;
					cl1[1]++;
					maxn1[a[i].bi]=a[i].y;
				}
			}
		}
		int sum=0,sum1=0;
		for(int i=1;i<=n;i++){
			sum+=maxn[i];
			sum1+=maxn1[i];
		}
		sort(a+1,a+1+n,cmp4);
		cout<<max(sum,sum1)<<endl;
	}
	return 0;
} 
