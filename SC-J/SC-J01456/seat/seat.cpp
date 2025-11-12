#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	int sb;
	cin>>sb;
	int r=sb;
	v.push_back(sb);
	for(int i=0;i<n*m-1;i++){
		cin>>sb;
		v.push_back(sb);
	}
	sort(v.begin(),v.end(),cmp);
//	for(int i=0;i<n*m;i++){
//		cout<<v[i]<<endl;
//	}
	int poi=find(v.begin(),v.end(),r)-v.begin()+1;
	int y,x;
//	cout<<poi<<endl;
	y=ceil((poi)*1.0/n);
	x=(y%2==0 ? (poi%n!=0 ? n-(poi%n)+1 : 1) : (poi%n!=0 ? poi%n : n));
	cout<<y<<" "<<x<<endl;
	return 0;
	
}