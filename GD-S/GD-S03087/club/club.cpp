#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int INF=0x3f3f3f3f;
int T,n;
struct node{
	int id,x;
	bool fl,mx,mimx,mi;
}a[N],b[N],c[N];
struct node1{
	int a,b,c;
}aa[N];
bool cmp(node aa,node bb){
	return aa.x>bb.x;
}
bool cmp1(node a,node b){
	return a.id<b.id;
}
void solve1(int& ans1,int& ans2,int& ans3,int& check1,int& check2,int& check3){
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(check1==0){
				break;
			}
			if(a[i].fl==1){
				continue;
			}
			if(a[i].mx==0){
				continue;
			}
			ans1+=a[i].x;
			a[i].fl=1;
			check1--;
		}
		for(int i=1;i<=n;i++){
			if(check2==0){
				break;
			}
			if(b[i].fl==1){
				continue;
			}
			if(b[i].mx==0){
				continue;
			}
			ans2+=b[i].x;
			b[i].fl=1;
			check2--;
		}
		for(int i=1;i<=n;i++){
			if(check3==0){
				break;
			}
			if(c[i].fl==1){
				continue;
			}
			if(c[i].mx==0){
				continue;
			}
			ans3+=c[i].x;
			c[i].fl=1;
			check3--;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].fl==1||b[i].fl==1||c[i].fl==1){
				a[i].fl=b[i].fl=c[i].fl=1;
			}
		}
}
void solve2(int& ans1,int& ans2,int& ans3,int& check1,int& check2,int& check3){
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(check1==0){
				break;
			}
			if(a[i].fl==1){
				continue;
			}
			if(a[i].mimx==0){
				continue;
			}
			ans1+=a[i].x;
			a[i].fl=1;
			check1--;
		}
		for(int i=1;i<=n;i++){
			if(check2==0){
				break;
			}
			if(b[i].fl==1){
				continue;
			}
			if(b[i].mimx==0){
				continue;
			}
			ans2+=b[i].x;
			b[i].fl=1;
			check2--;
		}
		for(int i=1;i<=n;i++){
			if(check3==0){
				break;
			}
			if(c[i].fl==1){
				continue;
			}
			if(c[i].mimx==0){
				continue;
			}
			ans3+=c[i].x;
			c[i].fl=1;
			check3--;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].fl==1||b[i].fl==1||c[i].fl==1){
				a[i].fl=b[i].fl=c[i].fl=1;
			}
		}
}
void solve3(int& ans1,int& ans2,int& ans3,int& check1,int& check2,int& check3){
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(check1==0){
				break;
			}
			if(a[i].fl==1){
				continue;
			}
			if(a[i].mi==0){
				continue;
			}
			ans1+=a[i].x;
			a[i].fl=1;
			check1--;
		}
		for(int i=1;i<=n;i++){
			if(check2==0){
				break;
			}
			if(b[i].fl==1){
				continue;
			}
			if(b[i].mi==0){
				continue;
			}
			ans2+=b[i].x;
			b[i].fl=1;
			check2--;
		}
		for(int i=1;i<=n;i++){
			if(check3==0){
				break;
			}
			if(c[i].fl==1){
				continue;
			}
			if(c[i].mi==0){
				continue;
			}
			ans3+=c[i].x;
			c[i].fl=1;
			check3--;
		}
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp1);
		sort(c+1,c+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].fl==1||b[i].fl==1||c[i].fl==1){
				a[i].fl=b[i].fl=c[i].fl=1;
			}
		}
}
int maker1(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve1(ans1,ans2,ans3,check1,check2,check3);
	solve2(ans1,ans2,ans3,check1,check2,check3);
	solve3(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int maker2(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve1(ans1,ans2,ans3,check1,check2,check3);
	solve3(ans1,ans2,ans3,check1,check2,check3);
	solve2(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int maker3(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve2(ans1,ans2,ans3,check1,check2,check3);
	solve1(ans1,ans2,ans3,check1,check2,check3);
	solve3(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int maker4(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve2(ans1,ans2,ans3,check1,check2,check3);
	solve3(ans1,ans2,ans3,check1,check2,check3);
	solve1(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int maker5(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve3(ans1,ans2,ans3,check1,check2,check3);
	solve1(ans1,ans2,ans3,check1,check2,check3);
	solve2(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int maker6(){
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+n,cmp1);
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		a[i].fl=b[i].fl=c[i].fl=0;
	}
	int ans1=0,ans2=0,ans3=0,check1=n/2,check2=n/2,check3=n/2;
	solve3(ans1,ans2,ans3,check1,check2,check3);
	solve2(ans1,ans2,ans3,check1,check2,check3);
	solve1(ans1,ans2,ans3,check1,check2,check3);
	return ans1+ans2+ans3;
}
int anss;
void dfs(int k,int nw,int mn1,int mn2,int mn3){
	if(k==n+1){
		anss=max(anss,nw);
		return ;
	}
	if(mn1>0){
		nw+=a[k].x;
		dfs(k+1,nw,mn1-1,mn2,mn3);
		nw-=a[k].x;
	}
	if(mn2>0){
		nw+=b[k].x;
		dfs(k+1,nw,mn1,mn2-1,mn3);
		nw-=b[k].x;
	}
	if(mn3>0){
		nw+=c[k].x;
		dfs(k+1,nw,mn1,mn2,mn3-1);
		nw-=c[k].x;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
//	T=1; 
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
		}
		if(n==2){
			int s1=a[1].x+max(b[2].x,c[2].x),s2=b[1].x+max(a[2].x,c[2].x),s3=c[1].x+max(b[2].x,a[2].x);
			cout<<max(s1,max(s2,s3))<<endl;
			continue;
		}else if(n<=18){
			/*
			int ans=0,ans1=0;
			ans1+=a[1].x;
			ans1+=a[2].x;
			ans1+=b[3].x;
			ans1+=b[4].x;
			ans=max(ans,ans1);
			for(int i=1;i<=3;i++){
				ans1+=a[i].x;
				for(int j=1;j<=n;j++){
					if(j==i){
						continue;
					}
					ans1+=b[j].x;
					for(int k=1;k<=n;k++){
						if(k==j||k==i){
							continue;
						}
						ans1+=c[k].x;
						ans=max(ans,ans1);
						cout<<i<<" "<<j<<" "<<k<<" "<<ans1<<endl;
						ans1-=c[k].x;
					}
					ans1-=b[j].x;
				}
				ans1-=a[i].x;
			}
			cout<<ans<<endl;
			*/
			dfs(1,0,n/2,n/2,n/2);
			cout<<anss<<endl;
			anss=0;
			continue;
		}
		for(int i=1;i<=n;i++){
			a[i].id=b[i].id=c[i].id=i;
			a[i].fl=b[i].fl=c[i].fl=0;
			if(a[i].x==max(a[i].x,max(b[i].x,c[i].x))){
				a[i].mx=1;
				if(b[i].x==c[i].x){
					b[i].mi=c[i].mi=1;
					a[i].mimx=a[i].mi=b[i].mx=b[i].mimx=c[i].mx=c[i].mimx=0;
				}else if(b[i].x==min(a[i].x,min(b[i].x,c[i].x))){
					b[i].mi=1;
					c[i].mimx=1;
					a[i].mimx=a[i].mi=b[i].mx=b[i].mimx=c[i].mx=c[i].mi=0;
				}else{
					c[i].mi=1;
					b[i].mimx=1;
					a[i].mimx=a[i].mi=c[i].mx=c[i].mimx=b[i].mx=b[i].mi=0;
				}
			}
			if(b[i].x==max(a[i].x,max(b[i].x,c[i].x))){
				b[i].mx=1;
				if(a[i].x==c[i].x){
					a[i].mi=c[i].mi=1;
					b[i].mimx=b[i].mi=a[i].mx=a[i].mimx=c[i].mx=c[i].mimx=0;
				}else if(a[i].x==min(a[i].x,min(b[i].x,c[i].x))){
					a[i].mi=1;
					c[i].mimx=1;
					b[i].mimx=b[i].mi=a[i].mx=a[i].mimx=c[i].mx=c[i].mi=0;
				}else{
					c[i].mi=1;
					a[i].mimx=1;
					b[i].mimx=b[i].mi=c[i].mx=c[i].mimx=a[i].mx=a[i].mi=0;
				}
			}
			if(c[i].x==max(a[i].x,max(b[i].x,c[i].x))){
				c[i].mx=1;
				if(b[i].x==a[i].x){
					b[i].mi=a[i].mi=1;
					c[i].mimx=c[i].mi=b[i].mx=b[i].mimx=a[i].mx=a[i].mimx=0;
				}else if(b[i].x==min(a[i].x,min(b[i].x,c[i].x))){
					b[i].mi=1;
					a[i].mimx=1;
					c[i].mimx=c[i].mi=b[i].mx=b[i].mimx=a[i].mx=a[i].mi=0;
				}else{
					a[i].mi=1;
					b[i].mimx=1;
					c[i].mimx=c[i].mi=a[i].mx=a[i].mimx=b[i].mx=b[i].mi=0;
				}
			}
		}
		/*
		if(fl1==INF&&fl2==INF&&fl3==INF){
			solve1(ans1,ans2,ans3,check1,check2,check3);
			solve2(ans1,ans2,ans3,check1,check2,check3);
			solve3(ans1,ans2,ans3,check1,check2,check3);
		}else if(fl1<=fl2&&fl1<=fl3){
			if(fl2<=fl3){
				solve1(ans1,ans2,ans3,check1,check2,check3);
				solve2(ans1,ans2,ans3,check1,check2,check3);
				solve3(ans1,ans2,ans3,check1,check2,check3);
			}else{
				solve1(ans1,ans2,ans3,check1,check2,check3);
				solve3(ans1,ans2,ans3,check1,check2,check3);
				solve2(ans1,ans2,ans3,check1,check2,check3);
			}
		}else if(fl2<=fl1&&fl2<=fl3){
			if(fl1<=fl3){
				solve2(ans1,ans2,ans3,check1,check2,check3);
				solve1(ans1,ans2,ans3,check1,check2,check3);
				solve3(ans1,ans2,ans3,check1,check2,check3);
			}else{
				solve2(ans1,ans2,ans3,check1,check2,check3);
				solve3(ans1,ans2,ans3,check1,check2,check3);
				solve1(ans1,ans2,ans3,check1,check2,check3);
			}
		}else{
			if(fl1<=fl2){
				solve3(ans1,ans2,ans3,check1,check2,check3);
				solve1(ans1,ans2,ans3,check1,check2,check3);
				solve2(ans1,ans2,ans3,check1,check2,check3);
			}else{
				solve3(ans1,ans2,ans3,check1,check2,check3);
				solve2(ans1,ans2,ans3,check1,check2,check3);
				solve1(ans1,ans2,ans3,check1,check2,check3);
			}
		}
		*/
		cout<<max(maker1(),max(maker2(),max(maker3(),max(maker4(),max(maker5(),maker6())))))<<endl;
	}
	return 0;
} 
