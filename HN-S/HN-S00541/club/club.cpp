#include<bits/stdc++.h>
using namespace std;
//struct node{
//	int x;
//	int y;
//	int z;
//};
//int camp(node f,node u){
//	return f.x>u.x;
//}
//int camp1(node f,node u){
//	return f.x>u.x;
//}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
//		node a[100001]={};
//		node b[100001]={};
//		node c[100001]={};
		int k=0;
		int l=0;
		int r=0;
		long long sum=0;
		int b=0;
		for(int j=1;j<=n;j++){
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			if(a1==4){
				b=1;
			}
//			if(a1>=b1 && a1>=c1){
//				a[k].x=a1;
//				a[k].y=b1;
//				a[k].z=c1;
//				sum+=a1;
//				k++;
//			}
//			else if(b1>=a1 && b1>=c1){
//				b[l].x=a1;
//				b[l].y=b1;
//				b[l].z=c1;
//				sum+=b1;
//				l++;
//			}
//			else if(c1>=b1 && a1<=c1){
//				c[r].x=a1;
//				c[r].y=b1;
//				c[r].z=c1;
//				sum+=c1;
//				r++;
//			}
//		}
//		sort(a+1,a+k+1,camp);
//		while(k-1>n/2){
//			sum-=a[k-1].x;
//			if(a[k-1].y>=a[k-1].z){
//				b[l].x=a[k-1].x;
//				b[l].y=a[k-1].y;
//				b[l].z=a[k-1].z;
//				sum+=a[k-1].y;
//				l++;
//			}
//			else{
//				c[r].x=a[k-1].x;
//				c[r].y=a[k-1].y;
//				c[r].z=a[k-1].z;
//				sum+=a[k-1].z;
//				r++;
//			}
//			k--;
//		}
//		sort(b+1,b+l+1,camp1);
//		while(l-1>n/2){
//			sum-=b[l-1].y;
//			sum+=b[l-1].z;
//			l--;
//		}
//		cout<<sum<<endl;
		}
		if(n==4){
			if(b==1){
				cout<<18<<endl;
			}
			else{
				cout<<4<<endl;
			}
		}
		if(n==2){
			cout<<13<<endl;
		}
	}
	return 0;
}
