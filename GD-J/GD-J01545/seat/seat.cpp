#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=111;
int n,m;
int sum,me,cnt;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int find(int x){
	int l=1,r=sum;
	while(l<=r){
		int mid=(l+r)/2;
		if(x==a[mid]){
			return mid;
		}
		else if(x<a[mid]){
			l=mid+1;
		}
		else if(x>a[mid]){
			r=mid-1; 
		}
	}
	return r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	me=a[1];
	sort(a+1,a+sum+1,cmp);
	cnt=find(me);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				ans+=1;
				if(ans==cnt){
					cout<<i<<" "<<j;
					return 0;
				}	
			}
		}	
		else{
			for(int j=1;j<=n;j++){
				ans+=1;
				if(ans==cnt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
