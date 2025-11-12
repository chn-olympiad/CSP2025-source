#include<bits/stdc++.h>
using namespace std;
int n;
struct student{
	int s[5];
	int mi,ma,zh;
	int cha;
}a[100005];
int mi(int a,int b,int c){
	if(a<b&&a<c){
		return 1;
	}else if(b<a&&b<c){
		return 2;
	}
	return 3;
}
int ma(int a,int b,int c){
	if(a>=b&&a>=c){
		return 1;
	}else if(b>=a&&b>=c){
		return 2;
	}else{
		return 3;
	}
}
bool cmp(student a,student b){
	return a.cha<=b.cha;
	return 0;
}
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		sum=0;
		scanf("%d",&n);
		getchar();
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].s[1],&a[i].s[2],&a[i].s[3]);
			getchar();
			a[i].mi=mi(a[i].s[1],a[i].s[2],a[i].s[3]);
			a[i].ma=ma(a[i].s[1],a[i].s[2],a[i].s[3]);
			a[i].zh=6-a[i].mi-a[i].ma;
			a[i].cha=a[i].s[a[i].ma]-a[i].s[a[i].zh];
		}
		sort(a+1,a+n+1,cmp);
		int st[5]={0};
		for(int i=1;i<=n;i++){
			st[a[i].ma]++;
			sum+=a[i].s[a[i].ma];
		}
		for(int i=1;i<=3;i++){
			if(st[i]>n/2){
				for(int j=1;j<=n;j++){
					if(st[i]==n/2){
						break;
					}
					if(a[j].ma==i){
						sum-=a[j].cha;
						st[i]--;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

