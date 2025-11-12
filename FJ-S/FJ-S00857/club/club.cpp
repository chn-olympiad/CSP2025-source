#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,num;
struct stu{
	int x,y,z;
}a[100001];
bool cmp(stu a,stu b){
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	return a.z<b.z;
}
void dfs(int i){
	int k=max(a[i].x,a[i].y),l;
	k=max(k,a[i].z);
	if(a[i].x==k&&a[i].y==k&&a[i].z==k){
		l=min(a1,a2);
		l=min(l,a3);
		num+=a[i].x;
		if(l==a1){a1++;}else{if(l==a2){a2++;}else{a3++;}}
		return;
	}
	if(a[i].x==k&&a[i].y==k){
		if(a1>=a2)a2++;
		else a1++;
		num+=a[i].x;
		return;
	}
	if(a[i].z==k&&a[i].y==k){
		if(a2>=a3)a3++;
		else a2++;
		num+=a[i].y;
		return;
	}
	if(a[i].x==k&&a[i].z==k){
		if(a1>=a3)a3++;
		else a1++;
		num+=a[i].x;
		return;
	}
	if(a[i].x==k){
		if(a1==n/2){
			if(a[i].y>=a[i].z){
				num+=a[i].y;
				a2++;
				return;
			}else{
				num+=a[i].z;
				a3++;
				return;
			} 
		}else{
			num+=a[i].x;
			a1++;
			return;
		}
	}
	if(a[i].y==k){
		if(a2==n/2){
			if(a[i].x>=a[i].z){
				num+=a[i].x;
				a1++;
				return;
			}else{
				num+=a[i].z;
				a3++;
				return;
			} 
		}else{
			num+=a[i].y;
			a2++;
			return;
		}
	}
	if(a[i].z==k){
		if(a3==n/2){
			if(a[i].x>=a[i].y){
				num+=a[i].x;
				a1++;
				return;
			}else{
				num+=a[i].y;
				a2++;
				return;
			} 
		}else{
			num+=a[i].z;
			a3++;
			return;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		a1=0,a2=0,a3=0,num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=n;i>=1;i--){
			dfs(i);
		}
		cout<<num<<endl;
	}
	return 0;
}
