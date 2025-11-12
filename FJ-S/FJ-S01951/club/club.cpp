#include <bits/stdc++.h>
using namespace std;
int n,t,k;
long long sum[5];
struct node{
	int x,y,z;
}a1[50001],a2[50001],a3[50001],a[100001];

bool arr1(node c,node d){
	return c.x>d.x;
}
bool arr2(node c,node d){
	return c.y>d.y;
}
bool arr3(node c,node d){
	return c.z>d.z;
}
int main(){
		freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	cin>>t;
	k=t;
	while(t>0){
		cin>>n;
		int x1=0,y1=0,z1=0;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y){
				if(a[i].x>a[i].z){
					a1[x1]=a[i];
					x1++;
				}else{
					a3[z1]=a[i];
					z1++;
				}
			}else{
				if(a[i].y>a[i].z){
					a2[y1]=a[i];
					y1++;
				}else{
					a3[z1]=a[i];
					z1++;
				}
			}
		}
		sort(a1,a1+x1,arr1);
		sort(a2,a2+y1,arr2);
		sort(a3,a3+z1,arr3);

		for(int j=0;j<min(n/2,x1);j++){
			sum[t]+=a1[j].x;
		}
		if(x1>n/2){
			for(int i=n/2;i<x1;i++){
				sum[t]+=max(a1[i].y,a1[i].z);
			}
		}
		for(int j=0;j<min(n/2,y1);j++){
			sum[t]+=a2[j].y;
		}
		if(y1>n/2){
			for(int i=n/2;i<y1;i++){
				sum[t]+=max(a2[i].x,a2[i].z);
			}
		}
		for(int j=0;j<min(n/2,z1);j++){
			sum[t]+=a3[j].z;
		}	
		cout<<sum<<endl;
		t--;
	}
	for(int i=k;i>0;i--){
		cout<<sum[i]<<endl;
	}
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

