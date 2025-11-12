#include<bits/stdc++.h>
using namespace std;
int n;
struct {
	int x,y,z;
}a[100000];
int sum;//满意值总和 
int cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int a1=0,a2=0,a3=0;
	while(t!=0){
		cin>>n;
		cnt=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
		int d=max(a[i].x,max(a[i].y,a[i].z));
			sum=sum+d;
			
		}
		cout<<sum<<endl;
		t--;
	}
	
	return 0;
}
