#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
const int N=1e5+47;
struct re{
	int a1,a2,a3,t;
}a[N];
bool cmp1(re x,re y){
	return x.a1>y.a1;
}
bool cmp2(re x,re y){
	return x.a2>y.a2;
}
bool cmp3(re x,re y){
	return x.a3>y.a3;
}
int f[N];
int n,sum;
bool checka(){
	for(int i=1;i<=n;i++){
		if(a[i].a2!=0||a[i].a3!=0)return 1;
	}
	return 0;
}
bool checkb(){
	for(int i=1;i<=n;i++){
		if(a[i].a3!=0)return 1;
	}
	return 0;
}
void sort1(){
	int o=0;
	sort(a+1,a+1+n,cmp1);
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<a[i].a1<<" "<<a[i].a2<<" "<<a[i].a3<<"\n";
//	}
	for(int i=1;i<=n;i++){
		if(f[a[i].t]==0){
			sum+=a[i].a1;
			f[a[i].t]=1;
			o++;
	//		cout<<a[i].a1<<" "<<1<<"\n";
			if(o==n/3)break;
		}
	}
}
void sort2(){
	int o1=0;
	sort(a+1,a+1+n,cmp2);
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<a[i].a1<<" "<<a[i].a2<<" "<<a[i].a3<<"\n";
//	}
	for(int i=1;i<=n;i++){
		if(f[a[i].t]==0){
			sum+=a[i].a2;
			f[a[i].t]=1;
			o1++;
	//		cout<<a[i].a2<<" "<<2<<"\n";
			if(o1==n/3)break;
		}
	}
}
void sort3(){
	int o2=0;
	sort(a+1,a+1+n,cmp3);
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		cout<<a[i].a1<<" "<<a[i].a2<<" "<<a[i].a3<<"\n";
//	}
	for(int i=1;i<=n;i++){
		if(f[a[i].t]==0){
			sum+=a[i].a3;
			f[a[i].t]=1;
			o2++;
	//		cout<<a[i].a3<<" "<<3<<"\n";
			if(o2==n/3)break;
		}
	}
}
void SORT(int u1,int u2,int u3){
	int f1=0,f2=0,f3=0;
	if(u1>=max(u2,u3))sort1(),f1=1;
	else if(u2>=max(u1,u3))sort2(),f2=1;
	else if(u3>=max(u2,u1))sort3(),f3=1;
	if(f1==1&&u2>=u3)sort2(),f2=1;
	else if(f1==1&&u3>=u2)sort3(),f3=1;
	else if(f2==1&&u1>=u3)sort1(),f1=1;
	else if(f2==1&&u3>=u1)sort3(),f3=1;
	else if(f3==1&&u1>=u2)sort1(),f1=1;
	else if(f3==1&&u2>=u1)sort2(),f2=1;
	if(f1==0)sort1();
	else if(f2==0)sort2();
	else if(f3==0)sort3();
}
void solve(){
	cin>>n;
	sum=0;
	int u1=0,u2=0,u3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		u1+=a[i].a1;
		u2+=a[i].a2;
		u3+=a[i].a3;
		a[i].t=i;
	}
	if(checkb()==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i].a1+a[j].a2);
				sum=max(sum,a[i].a2+a[j].a1);
			}
		}
	}else if(checka()==0){
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;i++)sum+=a[i].a1;
	}else if(n%3==1){
		SORT(u1,u2,u3);
		int p;
		for(int i=1;i<=n;i++){
			if(f[a[i].t]==0)p=i;
		}
		sum+=max(max(a[p].a1,a[p].a2),a[p].a3);
	}else if(n%3==0){
		SORT(u1,u2,u3);
	}else{
		if(n>2)SORT(u1,u2,u3); 
		int p1=0,p2=0;
		for(int i=1;i<=n;i++){
			if(f[a[i].t]==0&&p1!=0)p2=i;
			if(f[a[i].t]==0&&p2!=0)p1=i;
		}
		sum+=max(max(a[p1].a1,a[p1].a2),a[p1].a3);
		sum+=max(max(a[p2].a1,a[p2].a2),a[p2].a3);
	}
	cout<<sum<<"\n";
	for(int i=1;i<=n;i++){
		a[i].a1=a[i].a2=a[i].a3=a[i].t=0;
		f[i]=0;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
1
4
1 2 3
2 3 4
3 4 5
4 5 6

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
