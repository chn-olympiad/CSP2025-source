#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans=0;
int mmax;
int f[100005];
struct node{
	int m1;
	int m2;
	int m3;
};
node a[100005];
void go(int f1,int f2,int f3,int mm,int p){
	if(p>n){
		ans=max(ans,mm);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			if(f1+1<=mmax){
				go(f1+1,f2,f3,mm+a[p].m1,p+1);
			}
		}
		if(i==2){
			if(f2+1<=mmax){
				go(f1,f2+1,f3,mm+a[p].m2,p+1);
			}
		}
		if(i==3){
			if(f3+1<=mmax){
				go(f1,f2,f3+1,mm+a[p].m3,p+1);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
		}
		mmax=n/2;
		ans=0;
		go(0,0,0,0,1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 