#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tmp;
	for(int i=0;i<n*m;i++){
		int t;
		cin>>t;
		if(i==0) tmp=t;
		a.push_back(t);
	}
	sort(a.begin(),a.end(),cmp);
//	int l,r,mid;
//	l=0,r=a.size()-1;
//	while(1){
//		if(a[l]==tmp) break;
//		mid=l+(r-l)/2;
//		if(a[mid]>tmp){
//			r=mid-1;
//		}
//		else l=mid;
//	}
	int l;
	for(int i=0;i<n*m;i++) if(a[i]==tmp) l=i+1;
	int h,k;
//	cerr<<l;
	if(l%n==0){
		k=l/n;
		h=n;
	}
	else{
		k=(l/n)+1;
		if(k&1) h=l%n;
		else h=(n-(l%n))+1;
	}
	cout<<k<<" "<<h;
	return 0;
}
/*
2 2
98 99 100 97

*/
