//GZ-S00313 贵州省 王天垒 520123201106071230 贵阳市白云区华师一学校 初三 
#include<bits/stdc++.h>
const long long N=500001;
using namespace std;
int T;
int n;
struct node{
	long long like;
	long long club;
	long long people;
	long long id;
	bool student;
}a[N];
bool cmp(node x,node y){
	return x.like>y.like;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>n;
		long long cnt=0;
		long long Max=0;
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[++cnt].like;
				a[cnt].club=j;
				a[cnt].id=i;
				a[n].student=0;
				a[cnt].people=0;
			}
		}
		sort(a+1,a+1+3*n,cmp);
		for(long long j=1;j<=3*n;j++){
			ans=0;
			for(long long i=j;i<=3*n+j-1;i++){
				if(a[a[i%(3*n)].id].student==0&&a[a[i%(3*n)].club].people<n/2){
					a[a[i%(3*n)].id].student=1;
					a[a[i%(3*n)].club].people++;
					ans+=a[i%(3*n)].like;
				}
			}
			a[1].people=0;
			a[2].people=0;
			a[3].people=0;
			for(long long i=1;i<=n;i++){
				a[i].student=0;
			}
			Max=max(Max,ans);
		}
		cout<<Max<<endl;
	}
	return 0;
}
