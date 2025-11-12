#include<bits/stdc++.h>
using namespace std;
struct k{
	bool r=false;
	long long num;
	int han,le;
}a[1003];
bool cmp(k e,k t){
	return e.num>t.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i].num;
		if(i==0){
			a[i].r=true;
		}
	}
	sort(a,a+n*m,cmp);
	int hang=1,lie=1;
	int tt=1;
	for(int i=0;i<=n*m-1;i++){
		if(a[i].r==true){
			cout<<lie<<" "<<hang;
		}
		if(hang>=n&&tt==1){
			hang=n+1;
			tt=-1;
			lie++;
		}
		if(hang<=1&&tt==-1){
			hang=0;
			lie++;
			tt=1;
		}
		hang+=tt;
	}
	return 0;
}

