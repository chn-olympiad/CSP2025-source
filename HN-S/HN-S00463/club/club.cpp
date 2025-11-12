////10~30分
#include<bits/stdc++.h>
using namespace std;
long long n,a[10005][3],b[4],maax[10005],ans,k;
int t;
bool cmd(int x,int y){
	return x>y;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
			cin>>a[i][j];
			}
			maax[i]=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;++j){
			if(maax[i]==a[i][j])b[j]++;
			}
			ans+=maax[i];
		}
		//if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2){
			cout<<ans<<endl;
		//}//else{
		//sort(maax,maax+n,cmd);
		//	for(int i=1;i<n;i++){
		//		if(maax[1]==maax[i]){
		//			k++;
		//		}
		//		cout<<k<<endl;
		//		if(k==n/2){
		//			cout<<maax[0]*k<<endl;
		//			break;
		//		}
		//	}
			//cout<<ans-1<<endl;
		//}
	}
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;
long long n,a[10005][3],b,c[10005],d[10005]={3},maax,sum,z;
int t;
void s(int x,int y){
	int w;
	if(x!=1)w+=s(a[x-1]a[y]);
	else w+=s(a[1],a[y]);
	return w;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
			cin>>b;//可换成一个int变量 b
			if(b!=0){
				c[i]++;//记录非0数
				z*=c[i];//加的max次数 
				a[i][ans]=b;
			}
			}
		} 
		for(int x=1;x<=z;++x){
			//for(int i=n;i>=1;--i){
			//	for(int j=1;j<=c[n-i+1];++j){
			//		sum+=a[i][d[i]];
			//		d[i]++;
			//		a[1][d[1]]+a[i][d[4]]+a[3][d[3]]+a[2][d[2]];
					
			//		for(int i=1;i<=3;i++)d[1]++;
			//		d[2]++;
			maax=max(s(n,x),s(n,x-1));
		}
		cout<<maax<<endl;
	}
	return 0;
} */
