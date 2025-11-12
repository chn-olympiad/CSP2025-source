#include<bits/stdc++.h>
using namespace std;
struct man{
	pair<int,int>b[3];
	bool operator < (const man z){
		if(max(this->b[0].first,max(this->b[1].first,this->b[2].first))==max(z.b[0].first,max(z.b[1].first,z.b[2].first))){
			return this->b[0].first+this->b[1].first+this->b[2].first<z.b[0].first+z.b[1].first+z.b[2].first;
		}else return max(this->b[0].first, max(this->b[1].first, this->b[2].first) )>max(z.b[0].first,max(z.b[1].first,z.b[2].first) );
	}
};
void mai(){
	int n,out=0;
	cin>>n;
	vector<man>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].b[0].first>>a[i].b[1].first>>a[i].b[2].first;
		a[i].b[0].second=0;a[i].b[1].second=1;a[i].b[2].second=2;
	}
	sort(a.begin(),a.end());
	int add[3];
	memset(add,0,sizeof add);
	for(int i=0;i<n;i++){
		sort(&a[i],&a[i]+3);
		if(add[a[i].b[0].second]<n/2){
			//ok.
			add[a[i].b[0].second]++;
			out+=a[i].b[0].first;
		}else if(add[a[i].b[1].second]<n/2){
			add[a[i].b[1].second]++;
			out+=a[i].b[1].first;
		}else {
			add[a[i].b[2].second]++;
			out+=a[i].b[2].first;
		}
		
	}
	cout<<out<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)mai();
	return 0;
}

