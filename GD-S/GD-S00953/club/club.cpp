#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int xb[10004];
int da[10004];
int ca[10004];
int xi[10004];
int n;
int cmp(int x,int y){
	if(x>y)
	{
		swap(ca[x],ca[y]);
		swap(xb[x],xb[y]);
	}
	return x>y;
}

int solve(){
	cin>>n;
	long long ans=0;
	
	for(int i=1;i<=n;i++){
		int t1,t2,t3;
		cin>>t1;
		cin>>t2;
		cin>>t3;
		da[i]=max(max(t1,t2),t3);
		xi[i]=min(min(t1,t2),t3);
		ca[i]=da[i]+da[i]+xi[i]-t1-t2-t3;
		ans+=xi[i];
		da[i]=da[i]-xi[i];
	}
	sort(da,da+n,cmp);
	sort(ca,ca+n,cmp);
	int a1=0,a2=0,a3=0;
	for(int i=1;i<=n;i--){
		if(a1<=n/2){
			
		}
	}
	
	
	
	
}






int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	for(int i=1;i<=10004;i++){
		xb[i]=i;
	}
	for(int i=0;i<t;i++){
		solve();

	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
