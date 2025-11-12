#include<bits/stdc++.h>
using namespace std;

int quyu=998244353,m,n,a[5005],l=1,r,kede;
int chayixia1(int c,int d){
	int dadadade=0;
	for(int i=c;i<=d;i++){
		dadadade=max(dadadade,a[i]);
	}
	return dadadade;
}
int cha2(int c,int d){
	int yuansh=0;
	for(int i=c;i<=d;i++){
		yuansh+=a[i];
	}
	return yuansh;
}

int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	r=3;
	for(int i=1;i<=n;i++) cin>>a[i];
	int zong=a[1]+a[2]+a[3];
	int maxx=max(a[1],max(a[2],a[3]));
	
	while(r>l){
		if(r-l>=n) break;
		if(r-l<2){
			r++;
			zong+=a[r]-a[l];
			maxx=chayixia1(l,r);
			continue;
		}
		if(r>n){
			r=r-l+1+1;
			l=1;
			zong = cha2(l,r);
			maxx=chayixia1(l,r);
			continue;
		}
		if(zong<=2*maxx){
			l++;
			r++;
			zong+=a[r]-a[l-1];
			maxx=chayixia1(l,r);
			continue;
		}
		

		kede++;
		kede=kede%quyu;
		l++;
		r++;
		zong+=a[r]-a[l-1];
		maxx=chayixia1(l,r);
		
		
	}
	cout<<(kede%quyu);
	
	return 0;
}
