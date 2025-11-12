#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Cy{
	int zd,cd;
	int zdz,cdz;
}r[N];
bool cmp(Cy a,Cy b)
{
	return a.zd-a.cd>b.zd-b.cd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long myd=0;
		int num[4];
		for(int i=1;i<=3;i++){
			num[i]=n/2;
		}
		for(int i=1;i<=n;i++){
			int m[4],d[4];
			for(int j=1;j<=3;j++){
				cin>>m[j];
				d[j]=m[j];
			}
			sort(m+1,m+4);
			r[i].zd=m[3];
			r[i].cd=m[2];
			for(int j=1;j<=3;j++){
				if(r[i].zd==d[j]){
					r[i].zdz=j;
				}
				else if(r[i].cd==d[j]){
					r[i].cdz=j;
				}
			}
		}
		sort(r+1,r+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(num[r[i].zdz]<=0){
				num[r[i].cdz]--;
				myd+=r[i].cd;
			}
			else{
				num[r[i].zdz]--;
				myd+=r[i].zd;
			}
		}
		cout<<myd<<endl; 
	}
	return 0;
}
