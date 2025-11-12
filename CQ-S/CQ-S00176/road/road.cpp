#include <bits/stdc++.h>
using namespace std;
struct road{
	int a,b;
	int mo;
};
road a[1000001];
int c[100001];
bool cmp(road aa,road bb){
	if(aa.mo==0&&bb.mo==0){
		if(aa.a+aa.b<bb.a+bb.b)return true;
	}
	int mo1=aa.mo,mo2=bb.mo;
	if(!mo1)mo1=1;
	if(!mo2)mo2=1;
	int dd=(aa.a+aa.b)/mo1;int ee=(bb.a+bb.b)/mo2;
	if(dd<ee)return true;
	return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].a>>a[i].b>>a[i].mo;
	}
	for(int i=m+1;i<=m+k;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+m+k+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i].mo==0)cnt+=a[i].a+a[i].b;
		else cnt+=a[i].mo;
	}
	cout<<cnt;
	return 0;
} 
