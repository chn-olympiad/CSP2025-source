#include<bits/stdc++.h>
using namespace std;
struct nod{
	int ar[3],mai;
	bool used;
}arr[101010];
bool cmp1(nod m,nod n){
	return m.ar[0]>n.ar[0];
}
bool cmp2(nod m,nod n){
	return m.ar[1]>n.ar[1];
}
bool cmp3(nod m,nod n){
	return m.ar[2]>n.ar[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a[3];
		int n;
		cin>>n;
		int t1=n/2;
		int c=0;
		a[0]=0;
		a[1]=0;
		a[2]=0;
		for(int i=0;i<n;i++){
			cin>>arr[i].ar[0]>>arr[i].ar[1]>>arr[i].ar[2];
			arr[i].used=0;
		}
		for(int i=0;i<n;i++){
			if(arr[i].ar[0]>arr[i].ar[1]&&arr[i].ar[0]>arr[i].ar[2]){
				arr[i].mai=0;
			}
			if(arr[i].ar[1]>arr[i].ar[0]&&arr[i].ar[1]>arr[i].ar[2]){
				arr[i].mai=1;
			}
			if(arr[i].ar[2]>arr[i].ar[1]&&arr[i].ar[2]>arr[i].ar[0]){
				arr[i].mai=2;
			}
		}
		sort(arr,arr+n,cmp1);
		c=0;
		for(int i=0;i<n;i++){
			if(c==t1)break;
			else if(arr[i].mai==0&&arr[i].used==0){
				arr[i].used=1;
				a[0]+=arr[i].ar[0];
			}
		}
		sort(arr,arr+n,cmp2);
		c=0;
		for(int i=0;i<n;i++){
			if(c==t1)break;
			else if(arr[i].mai==1&&arr[i].used==0){
				arr[i].used=1;
				a[1]+=arr[i].ar[1];
			}
		}
		sort(arr,arr+n,cmp3);
		c=0;
		for(int i=0;i<n;i++){
			if(c==t1)break;
			else if(arr[i].mai==2&&arr[i].used==0){
				arr[i].used=1;
				a[2]+=arr[i].ar[2];
			}
		}
		cout<<a[0]+a[1]+a[2];
	}
	
	return 0;
}
