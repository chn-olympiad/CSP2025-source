#include<bits/stdc++.h>
using namespace std;
struct ac{
	long long x,y,z;
}s[102222];
long long ans=0,ans2=0,ans3=0;
bool f1=1,f2=1,f3=1,f4=1;
bool cmp(ac xz,ac yz){
	if(xz.x>yz.x){
		return xz.x>yz.x;
	}
	else if(xz.y>yz.y){
		return xz.y>yz.y;
	}
	else{
		return xz.z>yz.z;
	}
}
bool cmp1(ac xx,ac yx){
	return xx.x>yx.x;
}
bool cmp2(ac xx,ac yx){
	return xx.y>yx.y;
}
bool cmp3(ac xx,ac yx){
	return xx.z>yx.z;
}
long long m,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(int j=1;j<=m;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].x>>s[i].y>>s[i].z;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].y!=0||s[i].z!=0){
				f1=0;
			}
			if(s[i].x!=0||s[i].z!=0){
				f2=0;
			}
			if(s[i].z!=0){
				f3=0;
			}
			if(s[i].x!=0||s[i].y!=0){
				f4=0;
			}
			if(f1+f2+f3==0){
				break;
			}
		}
		else if(f1==1&&f2==0&&f4==0){
			ans=0;
			sort(s+1,s+n+1,cmp1);
			for(int k=1;k<=n/2;k++){
				ans+=s[k].x;
			}
		}
		else if(f2==1&&f1==0&&f4==0){
			ans=0;
			sort(s+1,s+n+1,cmp2);
			for(int k=1;k<=n/2;k++){
				ans+=s[k].y;
			}
		}
		else if(f4==1&&f1==0&&f2==0){
			ans=0;
			sort(s+1,s+n+1,cmp3);
			for(int k=1;k<=n/2;k++){
				ans+=s[k].z;
			}
		}
		cout<<ans<<endl;
		f1=1;
		f2=1;
		f3=1;
		f4=1;
	}
	return 0;
}
/*
 2
 3
 1 0 0
 2 0 0
 9 0 0 
 4
 0 1 0 
 0 2 0 
 0 2 0
 0 1 0 
 */
