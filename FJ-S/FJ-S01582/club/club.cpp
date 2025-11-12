#include<bits/stdc++.h>
using namespace std;
int t,n,happy;
int a,b,c;
const int N=1e5+10;
struct node{
	int first;
	int second;
	int third;
}arr[N];
bool cmp(node x,node y){
	int z=max(max(x.first,x.second),x.third),l=max(max(y.first,y.second),y.third);
	if(z>l){
		if(y.second<x.second&&y.third<x.third&&y.first==l)return 0;
		else if(y.first<x.first&&y.third<x.third&&y.second==l)return 0;
		else if(y.first<x.first&&y.second<x.second&&y.third==l)return 0;
		else return 1;
	}else{
		if(y.second>x.second&&y.third>x.third&&x.first==z)return 1;
		else if(y.first>x.first&&y.third>x.third&&x.second==z)return 1;
		else if(y.first>x.first&&y.second>x.second&&x.third==z)return 1;
		else return 0;		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		a=b=c=happy=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d %d %d",&arr[i].first,&arr[i].second,&arr[i].third);
		stable_sort(arr+1,arr+1+n,cmp);
		for(int i=1;i<=n;++i){
			int maxn=max(arr[i].first,max(arr[i].second,arr[i].third));
			int second=0;
			if(maxn==arr[i].first){
				if(arr[i].second>arr[i].third){
					second=arr[i].second;
					if(a+1>n/2){
						++b;
						happy+=second;
					}else{
						++a;
						happy+=maxn;
					}
				}else{
					second=arr[i].third;
					if(a+1>n/2){
						++c;
						happy+=second;
					}else{
						++a;
						happy+=maxn;
					}		
				}
			}else if(maxn==arr[i].second){
				if(arr[i].first>arr[i].third){
					second=arr[i].first;
					if(b+1>n/2){
						++a;
						happy+=second;
					}else{
						++b;
						happy+=maxn;
					}
				}else{
					second=arr[i].third;
					if(b+1>n/2){
						++c;
						happy+=second;
					}else{
						++b;
						happy+=maxn;
					}		
				}
			}else{
				if(arr[i].first>arr[i].second){
					second=arr[i].first;
					if(c+1>n/2){
						++a;
						happy+=second;
					}else{
						++c;
						happy+=maxn;
					}
				}else{
					second=arr[i].second;
					if(c+1>n/2){
						++b;
						happy+=second;
					}else{
						++c;
						happy+=maxn;
					}		
				}
			}
		}
		printf("%d\n",happy);
	}
	return 0;
}
