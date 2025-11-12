#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int T;
int n;
int sum_max=0;
struct node{
	int a;
	int b;
	int c;
	int z;
}a[100010];
int lona=0,lonb=0,lonc=0;
bool cmp(node a,node b){
	return a.z>b.z;
//	if(a.a!=b.a) return a.a<b.a;
//	else if(a.b!=b.b) return a.b<b.b;
//	else if(a.c!=b.c) return a.c<b.c;
//	else return a.z<b.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		lona=0;
		lonb=0;
		lonc=0;
		sum_max=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a;
			cin>>a[i].b;
			cin>>a[i].c;
			a[i].z=a[i].a+a[i].b+a[i].c;
		}
		
		sort(a+1,a+n+1,cmp);
		int mid=n/2;
		
		for(int i=1;i<=n;i++){
			int t=0;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&lona+1<=mid){
				lona++;
				t=1;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c&&lonb+1<=mid){
				lonb++;
				t=2;
			} 
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b&&lonc+1<=mid){
				lonc++;
				t=3;
			}
			
			if(t==1){
				sum_max+=a[i].a;
			}
			else if(t==2){
				sum_max+=a[i].b;
			}
			else if(t==3){
				sum_max+=a[i].c;
			}
		}
		cout<<sum_max<<endl; 
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
