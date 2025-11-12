#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct f{
	int a,b,c,d,e;
}a[100005];
long long dp[200002];
bool cmp(f a,f b){
	return (a.d-a.e)>(b.d-b.e);
}
bool q1(f a,f b){
	return abs(a.b-a.c)>abs(b.b-b.c);
}
bool q2(f a,f b){
	return abs(a.a-a.c)>abs(b.a-b.c);
}
bool q3(f a,f b){
	return abs(a.a-a.b)>abs(b.a-b.b);
}
int main(){
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=max(max(a[i].a,a[i].b),a[i].c);
			if(a[i].d==a[i].a)a[i].e=max(a[i].b,a[i].c);
			else if(a[i].d==a[i].b)a[i].e=max(a[i].a,a[i].c);
			else a[i].e=max(a[i].a,a[i].b);
		}
		sort(a+1,a+n+1,cmp);
		int a1=0,a2=0,a3=0;
		long long h=0,aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			if(a[i].a==a[i].d&&aa==0&&bb==0&&cc==0){
				a1++;
				h+=a[i].a;
			}
			else if(a[i].b==a[i].d&&bb==0&&aa==0&&cc==0){
				a2++;
				h+=a[i].b;
			}
			else if(cc==0&&bb==0&&aa==0){
				a3++;
				h+=a[i].c;
			}
			else if(aa==1){
				if(a[i].b>a[i].c){
					a2++;
					h+=a[i].b;
				}
				else{
					a3++;
					h+=a[i].c;
				}
			}
			else if(bb==1){
				if(a[i].a>a[i].c){
					a1++;
					h+=a[i].a;
				}
				else{
					a3++;
					h+=a[i].c;
				}
			}
			else{
				if(a[i].a>a[i].b){
					a1++;
					h+=a[i].a;
				}
				else{
					a2++;
					h+=a[i].b;
				}
			}
			if(a1==n/2&&aa==0){
				sort(a+i+1,a+n+1,q1);
				aa=1;
			} 
			if(a2==n/2&&bb==0){
				sort(a+i+1,a+n+1,q2);
				bb=1;
			}
			if(a3==n/2&&cc==0){
				sort(a+i+1,a+n+1,q3);
				cc=1;
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
