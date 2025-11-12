#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
}arr[100001]; 
int cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		for(int i=0;i<m;++i){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			
		}
//		sort(arr,arr+m,cmp);
//		cout<<"zeshi:";
//		for(int i=0;i<m;++i){
//			cout<<arr[i].a<<" "<<arr[i].b<<" "<<arr[i].c<<"\n";
//		}
		int sum=0;
		int ac=0,bc=0,cc =0;
		for(int i =0;i<m;++i){
			if(arr[i].a>arr[i].b&&arr[i].a>arr[i].c&&ac<m/2){
				sum+=arr[i].a;
				ac++;
			}
			else if(arr[i].b>arr[i].a&&arr[i].b>arr[i].c&&bc<m/2){
				sum+=arr[i].b;
				bc++;
			}
			else if(arr[i].c>arr[i].a&&arr[i].c>arr[i].b&&cc<m/2){
				sum+=arr[i].c;
				cc++;
			}
			else if(arr[i].a>arr[i].b&&arr[i].b>arr[i].c&&ac<m/2){
				sum+=arr[i].a;
				ac++;
			}
			else if(arr[i].b>arr[i].c&&bc<m/2){
				sum+=arr[i].b;
				bc++;
			}
			else if(cc<m/2){
				sum+=arr[i].c;
				cc++;
			}
			else if(arr[i].a>arr[i].b){
				sum+=arr[i].a;
				ac++;
			}
			else {
				sum+=arr[i].b;
				bc++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} 
