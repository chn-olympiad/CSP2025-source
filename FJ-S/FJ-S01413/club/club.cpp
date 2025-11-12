#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[4][N],max1[4][N],max2[N]={0};
int minx(int a,int b,int c){
	if(a<b&&a<c){
		return a;
	}else if(b<a&&b<c){
		return b;
	}else{
		return c;
	}
}
int fun(int a,int b,int c,int n){
	if(a>n/2){
		return a;
	}else if(b>n/2){
		return b;
	}else{
		return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	max2[N]={0};
	while(t--){
		cin>>n;
		for(int i=0;i<n+5;i++){
			max1[0][i]=-1;
			max1[1][i]=-1;
			max1[2][i]=-1;
			a[0][i]=0; a[1][i]=0; a[2][i]=0;
	}
		int cnt0=0,cnt1=0,cnt2=0;
		for(int i=0;i<n;i++){	
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			if(max(a[0][i],max(a[1][i],a[2][i]))==a[0][i]){
				max1[0][i]=max(a[0][i],max(a[1][i],a[2][i]));
				cnt0++;
			}else if(max(a[0][i],max(a[1][i],a[2][i]))==a[1][i]){
				max1[1][i]=max(a[0][i],max(a[1][i],a[2][i]));
				cnt1++;
			}else{
				max1[2][i]=max(a[0][i],max(a[1][i],a[2][i]));
				cnt2++;
			}
			max2[i]=minx(max(a[0][i],a[1][i]),max(a[0][i],a[2][i]),max(a[1][i],a[2][i]));
		}
		long long sum=0;
			for(int i=0;i<n;i++){
				sum+=max(max1[0][i],max(max1[1][i],max1[2][i]));
			}
		if(cnt0<=n/2&&cnt1<=n/2&&cnt2<=n/2){
			cout<<sum<<'\n';			
		}else{
			int num=fun(cnt0,cnt1,cnt2,n);
			int x[n];
			for(int i=0;i<n;i++){
				x[i]=max(max1[0][i],max(max1[1][i],max1[2][i]))-max2[i];
			}
			sort(x,x+n);
			num=num-n/2;
			while(num--){
				int i=0;
				sum-=x[i];
				i++;
			}
			cout<<sum<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
