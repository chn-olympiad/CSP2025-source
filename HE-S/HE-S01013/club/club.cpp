#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],T1[100010];
int cnt1,cnt2,cnt3,c1e4;
long long ans;
struct B{
	int x,y,m;
	bool oort;
}T2[100010];
struct C{
	int x,y,z;
}T3[100010];
bool cmp1(B i,B j){
	if(i.m!=j.y)
		return i.m>j.m;
	return min(i.x,i.y)>min(j.x,j.y);
}
bool cmp2(C i,C j){
	if(i.x!=j.x)
		return i.x>j.x;
	else{
		if(i.y!=j.y)
			return i.y>j.y;
		else
			return i.z>j.z;
	}
	return 0;
}
long long spA(){
	memset(T1,sizeof(T1),0);
	long long t=0;
	for(int i=1;i<=n;i++){
		T1[i]=a[i][1];
	}
	sort(T1+1,T1+n+1);
	for(int i=n;i>n/2;i--)
		t+=T1[i];
	return t;
}
long long spB(){
	long long t=0;
	int Ca=0,Cb=0;
	for(int i=1;i<=n;i++){
		T2[i].x=a[i][1];
		T2[i].y=a[i][2];
		T2[i].m=max(T2[i].x,T2[i].y);
		if(T2[i].x<T2[i].y)
			T2[i].oort=1;
	}
	sort(T2+1,T2+n+1,cmp1);
	for(int i=1;i<=n;i++){
		if(T2[i].oort){
			if(Cb<n/2){
				t+=T2[i].y;
				Cb++;
			}
			else{
				t+=T2[i].x;
				Ca++;
			}
		}
		else{
			if(Ca<n/2){
				t+=T2[i].x;
				Ca++;
			}
			else{
				t+=T2[i].y;
				Cb++;
			}
		}
	}
	return t;
}
long long spC(){
	long long t=0;
	int Ca=0,Cb=0,Cc=0;
	for(int i=1;i<=n;i++){
		T3[i].x=a[i][1];
		T3[i].y=a[i][2];
		T3[i].z=a[i][3];
	}
	sort(T3+1,T3+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(T3[i].x&&Ca<n/2){
			t+=20000;
			Ca++;
		}
		else if(T3[i].y&&Cb<n/2){
			t+=20000;
			Cb++;
		}
		else if(T3[i].z&&Cc<n/2){
			t+=20000;
			Cc++;
		}
	}
	return t;
}
long long dfs(int t,int Ca,int Cb,int Cc,int Tot){
	if(t==n)
		return Tot;
	long long Tans=-1;
	if(Ca<n/2){
		Tans=max(Tans,dfs(t+1,Ca+1,Cb,Cc,Tot+a[t+1][1]));
	}
	if(Cb<n/2){
		Tans=max(Tans,dfs(t+1,Ca,Cb+1,Cc,Tot+a[t+1][2]));
	}
	if(Cc<n/2){
		Tans=max(Tans,dfs(t+1,Ca,Cb,Cc+1,Tot+a[t+1][3]));
	}
	return Tans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int q=1;q<=T;q++){
		memset(a,sizeof(a),0);
		cnt1=0;
		cnt2=0;
		cnt3=0;
		c1e4=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]!=0)
				cnt1++;
			if(a[i][2]!=0)
				cnt2++;
			if(a[i][3]!=0)
				cnt3++;
			if(a[i][1]==20000)c1e4++;
			if(a[i][2]==20000)c1e4++;
			if(a[i][3]==20000)c1e4++;
		}
		if(cnt2==0&&cnt3==0){
			printf("%lld\n",spA());
		}
		else if(cnt3==0){
			printf("%lld\n",spB());
		}
		else if(cnt1+cnt2+cnt3==c1e4){
			printf("%lld\n",spC());
		}
		else{
			printf("%lld\n",dfs(0,0,0,0,0));
		}
	}
	return 0;
}
