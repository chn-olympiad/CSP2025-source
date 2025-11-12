#include<bits/stdc++.h>
using namespace std;
struct student{
	long long zhi;
	bool r;
}mp[20000];
bool cmp(student a,student b){
	return a.zhi>b.zhi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,z=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(z==0) mp[z].r=true;
		else mp[z].r=false;
		cin>>mp[z].zhi;
		z++;
	}
	sort(mp,mp+n*m,cmp);
	long long i=1,j=1,k=0;
	while(k<=z){
		while(j<=n){
			if(mp[k].r){
				cout<<i<<" "<<j;
				return 0;
			}
			j++;k++;
		}
		j--;i++;
		while(j>=1){
			if(mp[k].r){
				cout<<i<<" "<<j;
				return 0;
			}
			j--;k++;
		}
		j++;
		i++;
	}
	return 0;
}