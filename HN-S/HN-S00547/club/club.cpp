#include<bits/stdc++.h> 
using namespace std;
struct node{
	int a1;
	int a2;
	int a3;
};
const int N=1e5+10;
int t;
int n;
node a[N];
int ans;
void dfs(int x1,int x2,int x3,int sum){
	if(x1+x2+x3==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && x1+1<=n/2){
			dfs(x1+1,x2,x3,sum+a[x1+x2+x3+1].a1);
		}
	    if(i==2 && x2+1<=n/2){
			dfs(x1,x2+1,x3,sum+a[x1+x2+x3+1].a2);
		}
		if(i==3 && x3+1<=n/2){
			dfs(x1,x2,x3+1,sum+a[x1+x2+x3+1].a3);
		}
	}
}
bool cmp1(node x,node y){
	return x.a1>y.a1;
}
bool cmp2(node x,node y){
	return x.a2>y.a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3; 
		}
		int fa=1,fb=1;
		for(int i=1;i<=n;i++){
			if(a[i].a2!=0 || a[i].a3!=0){
			    fa=0;
			}
			if(a[i].a3!=0){
				fb=0;
			}
		}
		if(fa==1){
			int sum1=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				sum1+=a[i].a1;
			}
			cout<<sum1<<endl;
		}
		else if(fb==1 && n>30){
			int suma=0,sumb=0;
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				suma+=a[i].a1;
			}
			for(int i=n/2+1;i<=n;i++){
				suma+=a[i].a2;
			}
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++){
				sumb+=a[i].a2;
			}
			for(int i=n/2+1;i<=n;i++){
				sumb+=a[i].a1;
			}
			cout<<max(suma,sumb)<<endl;
		}
		else{
		    dfs(0,0,0,0);
            cout<<ans<<endl;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
