#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],maxx[100005][3],fts[3][100005];
long long rs[3],rsm[3],ans;
void sortt(int x,int &A,int &B,int &C){
	if(a[x][A]<a[x][B]) swap(A,B);
	if(a[x][B]<a[x][C]) swap(B,C);
	if(a[x][A]<a[x][B]) swap(A,B);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--){
		for(int i=0;i<3;i++) rs[i]=rsm[i]=0;
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxx[i][0]=0,maxx[i][1]=1,maxx[i][2]=2;
			sortt(i,maxx[i][0],maxx[i][1],maxx[i][2]);
			fts[maxx[i][0]][rsm[maxx[i][0]]++]=a[i][maxx[i][1]]-a[i][maxx[i][0]];
			rs[maxx[i][0]]++,ans+=a[i][maxx[i][0]];
		}
		for(int i=0;i<3;i++) if(rs[i]>n/2){
			sort(fts[i],fts[i]+rsm[i],cmp);
//			cout<<"第一志愿未录取的影响值：\n";
			for(int j=0;j<rs[i]-n/2;j++) /*cout<<fts[i][j]<<endl*/ans+=fts[i][j];
		}
		cout<<ans<<endl;
 }
	return 0;
}

