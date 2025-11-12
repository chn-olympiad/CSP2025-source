#include<bits/stdc++.h>
using namespace std;
// wei ren min fu wu 
struct m{
int b[3];
int m;
void upd(){
if(b[0]>b[1]){if(b[0]>b[2])m=0;else m=2;}
else if(b[1]>b[2]) m=1;else m=2;}
}a[100005];
bool cmpm(m ma,m mb){
return ma.b[ma.m]<mb.b[mb.m];
}int cnt_[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;cin>>t;bool flag
	for(int ___=0;___<t;___++){
	int ans=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){cin>>a[i].b[0]>>a[i].b[1]>>a[i].b[2];a[i].upd();}
	sort(a,a+n,cmpm);
	for(int i=0;i<n&&cnt!=n;i++){
	if(cnt_[a[i].m]<(n>>1)){ans+=a[i].b[a[i].m];if(!a[i].b[a[i].m]){flag=true;break;;}
	a[i].b[0]=0;
	a[i].b[1]=0;
	a[i].b[2]=0;cnt++;cnt_[a[i].m]++;}
	else{a[i].b[a[i].m]=0;
	a[i].upd();sort(a,a+n,cmpm);i=0;}
	}cout<<ans<<endl;}
return 0;}
