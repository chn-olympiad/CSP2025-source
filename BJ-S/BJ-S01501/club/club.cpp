#include<bits/stdc++.h>
using namespace std;
int a [100005][4],t,n,v,m[4][100005],it[4],m2[100005];
long long tot;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	//cout<<t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			//cout<<"AAAAAAAA";
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//cout<<a[i][3]<<" ";
			if(a[i][1]-a[i][2]>0&&a[i][1]-a[i][3]>0){
				//b[1]++;
				it[1]++;
				m[1][it[1]]=a[i][1]-max(a[i][2],a[i][3]);
				m2[i]=1;
				//cout<<"1 ";
			}
			else if(a[i][2]-a[i][1]>0&&a[i][2]-a[i][3]>0){
				//b[2]++;
				it[2]++;
				m[2][it[2]]=a[i][2]-max(a[i][1],a[i][3]);
				m2[i]=2;
				//cout<<"2 ";
			}
			else if(a[i][3]-a[i][1]>0&&a[i][3]-a[i][2]>0){
				//b[3]++;
				it[3]++;
				m[3][it[3]]=a[i][3]-max(a[i][2],a[i][1]);
				m2[i]=3;
				//cout<<"3 ";
			}
			//cout<<"4 ";
		}
		//cout<<"|  ";
		int maxb=0;
		if(it[1]>n/2){
			maxb=1;
		}
		if(it[2]>n/2){
			maxb=2;
		}
		if(it[3]>n/2){
			maxb=3;
		}
		//cout<<it[maxb]<<" ";
		sort(m[maxb]+1,m[maxb]+1+it[maxb],cmp);
		//cout<<m[maxb][1]<<" ";
		//cout<<maxb<<" ";
		for(int i=1;i<=n/2;i++){
			tot+=m[maxb][i];
			//cout<<m[maxb][i]<<" ";
		}
		for(int i=1;i<=n;i++){
			a[i][maxb]=0;
			m[maxb][i]=0;
		}
		for(int i=1;i<=n;i++){
			tot+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<tot<<endl;
		tot=0;
		for(int i=1;i<=3;i++){
			it[i]=0;
		}
	}
	return 0;
}
