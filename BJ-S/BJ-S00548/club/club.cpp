#include<bits/stdc++.h>
using namespace std;
struct ru{
	int x,y,z,used;
}a[100005];
bool cmp1(ru x,ru y){
	if(x.x!=y.x) return x.x>y.x;
	else if(x.y!=y.y) return x.y<y.y;
	else return x.z<y.z;
}
bool cmp2(ru x,ru y){
	if(x.y!=y.y) return x.y>y.y;
	else return x.z<y.z;
}
bool cmp3(ru x,ru y){
	return x.z>y.z;
}
int t,n,d[20],num,sum;
void dfs(int x,int tmp1,int tmp2,int tmp3){
	if(x==n+1){
		cout<<"duan"<<endl;
		int tmp=0;
		for(int i=1;i<=n;i++) tmp+=(d[i]==1?a[i].x:d[i]==2?a[i].y:a[i].z);
		sum=max(tmp,sum);
		return ;
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<' ';
	cout<<endl;
	for(int i=1;i<=3;i++){
		if(i==1&&tmp1<n/2) d[x]=i,dfs(x+1,tmp1+1,tmp2,tmp3);
		if(i==2&&tmp2<n/2) d[x]=i,dfs(x+1,tmp1,tmp2+1,tmp3);
		if(i==3&&tmp3<n/2) d[x]=i,dfs(x+1,tmp1,tmp2,tmp3+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int l=1;
		num=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z,a[i].used=0;
		if(n<=15){ 
			dfs(1,0,0,0);
			cout<<sum<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		while(l<=n&&num<=n/2){
			if(a[l].y>a[l].x||a[l].z>a[l].x){l++; continue;}
			if(num+1>n/2) break;
			num++,sum+=a[l].x,a[l].used=1,l++;
		}	
		num=0; l=1;
		sort(a+1,a+n+1,cmp2);
		while(l<=n&&num<=n/2){
			if(a[l].z>a[l].y||a[l].used){l++; continue;}
			if(num+1>n/2) break;
			num++; sum+=a[l].y; a[l].used=1; l++;
		}	
		num=0; l=1;
		sort(a+1,a+n+1,cmp3);
		while(l<=n&&num<=n/2){
			if(a[l].used){l++; continue;}
			if(num+1>n/2) break;
			num++; sum+=a[l].z; l++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
