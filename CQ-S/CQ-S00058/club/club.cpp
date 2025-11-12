#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int a1,a2,a3,ans;
}a[500005];
bool cmp(node x,node y){
	int xx[4],yy[4];
	xx[1]=x.a1,xx[2]=x.a2,xx[3]=x.a3;
	yy[1]=y.a1,yy[2]=y.a2,yy[3]=y.a3;
	sort(xx+1,xx+4);
	sort(yy+1,yy+4);
	if(xx[3]-xx[2]!=yy[3]-yy[2]) return xx[3]-xx[2]>yy[3]-yy[2];
	else{
		return xx[3]-xx[1]>yy[3]-yy[1];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdin);
	cin>>T;
	while(T--){
		int s1=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=n;i>=1;i--){
			int maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
			a[i].ans=maxn;
			if(a[i].a1==a[i].a2&&a[i].a2==a[i].a3){
				if(s1>s2&&s2>s3) s3++;
				else if(s1>s3&&s3>s2) s2++;
				else if(s2>s1&&s1>s3) s3++;
				else if(s2>s3&&s3>s1) s1++;
				else if(s3>s2&&s2>s1) s1++;
				else if(s3>s1&&s3>s2) s2++;
			}
			else if(maxn==a[i].a1){
				if(a[i].a1==a[i].a2){
					if(s1>s2) s2++;
					else s1++;
				}
				else if(a[i].a1==a[i].a3){
					if(s3>s1) s1++;
					else s3++;
				}
				else s1++;
			}
			else if(maxn==a[i].a2){
				if(a[i].a2==a[i].a3){
					if(s2>s3) s3++;
					else s2++;
				}
				else s2++;
			}
			else{
				s3++;
			}
		}
		for(int i=n;i>=1;i--){
			if(s1<=n/2&&s2<=n/2&&s3<=n/2) break;
			else if(s1>n/2){
				if(a[i].ans==a[i].a1){
					s1--;
					a[i].ans=max(a[i].a2,a[i].a3);
				}
			}
			else if(s2>n/2){
				if(a[i].ans==a[i].a2){
					s2--;
					a[i].ans=max(a[i].a1,a[i].a3);
				}
			}
			else{
				if(a[i].ans==a[i].a3){
					s3--;
					a[i].ans=max(a[i].a2,a[i].a1);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i].ans;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
//CCF保佑我
