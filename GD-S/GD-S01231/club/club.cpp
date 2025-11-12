#include <bits/stdc++.h>
using namespace std;
int t,n,sum,sum1,f;
int a1,a2,a3;
struct node {
	int x,y,z;
}a[110000];
int main(){
	cin>>t;
	for(int i = 1;i<=t;i++){
		sum = 0;
		sum1 = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		a1 = 0;
		a2 = 0;
		a3 = 0;
		for(int i = 1;i<=n;i++){
			if(a[i].x < a[i].y || a[i].x < a[i].z){
				if(a[i].z < a[i].y && a2<n/2) {
					a2++;
					sum+=a[i].y;
					continue;
				}
				else if(a[i].z > a[i].y && a3<n/2){
					a3++;
					sum+=a[i].z;
					continue;
				}
			}
			if(a[i].y < a[i].z){
				if(a[i].z <a[i].x && a1<n/2) {
					a1++;
					sum+=a[i].x;
					continue;
				}
				else if(a[i].z > a[i].x && a3<n/2){
					a3++;
					sum+=a[i].z;
					continue;
				}
			}
			if(a1<n/2){
				sum+=a[i].x;
				
			} 
			else if(a2<n/2){
				sum+=a[i].y;
			} 
		}
		a1 = 0;
		a2 = 0;
		a3 = 0;
		for(int i = n;i>0;i--){
			if(a[i].x < a[i].y || a[i].x < a[i].z){
				if(a[i].z < a[i].y && a2<n/2) {
					a2++;
					sum1+=a[i].y;
					continue;
				}
				else if(a[i].z > a[i].y && a3<n/2){
					a3++;
					sum1+=a[i].z;
					continue;
				}
			}
			if(a[i].y < a[i].z){
				if(a[i].z <a[i].x && a1<n/2) {
					a1++;
					sum1+=a[i].x;
					continue;
				}
				else if(a[i].z > a[i].x && a3<n/2){
					a3++;
					sum1+=a[i].z;
					continue;
				}
			}
			if(a1<n/2){
				sum1+=a[i].x;
				a1++;
			} 
			else{
				sum1+=a[i].y;
				a2++;
				f++;
			} 
			
		}
		if(f == 1){
			cout<<sum1<<endl;
		}else{
			cout<<max(sum1,sum)<<endl;
		}
	}
	return 0;
} 

