#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > a;
int n,m,x,h=1,l=0;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		a.push_back({x,i});
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(i%n==0) l++;
		if(i%n!=0){
			if(l%2==1) h++;
			else h--;	
		}
		if(a[i].second==1){
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
} 
