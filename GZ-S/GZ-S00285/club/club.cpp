//GZ-S00285 贵阳市第一中学 樊墨涵 
#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
bool f=0;
struct node{
	int m1,m2,m3;
}a[100005];
bool cmp(node x,node y){
	return x.m1>y.m1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>k;
	while(k--){
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>a[i].m1>>a[i].m2>>a[i].m3;
			if(a[i].m2!=0||a[i].m3!=0){
				f=1;
			}
		}
		if(f==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].m1;
			}
			cout <<ans<<endl;
		}else{
			cout <<max(max(max(a[1].m1+a[2].m2,a[1].m1+a[2].m3),a[1].m2+a[2].m1),max(max(a[1].m2+a[2].m3,a[1].m3+a[2].m1),a[1].m3+a[2].m2))<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
