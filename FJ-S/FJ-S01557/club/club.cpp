#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a1,a2,a3;
	int ffat,sfat,tfat,c1,c2,c3;
	int cnt;
};
bool cmp1(ren a,ren b){
	return a.a1>b.a1;
}
bool cmp2(ren a,ren b){
	return a.a2>b.a2;
}
bool cmp3(ren a,ren b){
	return a.a3>b.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		bool IF1=0,IF2=0,IF3=0;
		cin>>n;
		ren a[n+5];
		for(int i=1;i<=n;++i){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1!=0) IF1=1;
			if(a[i].a2!=0) IF2=1;
			if(a[i].a3!=0) IF3=1;
			a[i].cnt=max(max(a[i].a1,a[i].a2),a[i].a3);
			if(a[i].a1>a[i].a2){
				if(a[i].a2>a[i].a3) a[i].ffat=a[i].a1,a[i].sfat=a[i].a2,a[i].tfat=a[i].a3;
				else if(a[i].a1>a[i].a3) a[i].ffat=a[i].a1,a[i].sfat=a[i].a3,a[i].tfat=a[i].a2;
				else a[i].ffat=a[i].a3,a[i].sfat=a[i].a1,a[i].tfat=a[i].a2;
			}
			else{
				if(a[i].a1>a[i].a3) a[i].ffat=a[i].a2,a[i].sfat=a[i].a1,a[i].tfat=a[i].a3;
				else if(a[i].a2>a[i].a3) a[i].ffat=a[i].a2,a[i].sfat=a[i].a3,a[i].tfat=a[i].a1;
				else a[i].ffat=a[i].a3,a[i].sfat=a[i].a2,a[i].tfat=a[i].a1;
			}
		}
		if(n==2){
			if((a[1].a1==a[1].cnt)&&(a[2].a1==a[2].cnt)){
				if(abs(a[1].ffat-a[1].sfat)>abs(a[2].ffat-a[2].sfat)) ans=a[1].ffat+a[2].sfat;
				else ans=a[1].sfat+a[2].ffat;
			}
			else if((a[1].a2==a[1].cnt)&&(a[2].a2==a[2].cnt)){
				if(abs(a[1].ffat-a[1].sfat)>abs(a[2].ffat-a[2].sfat)) ans=a[1].ffat+a[2].sfat;
				else ans=a[1].sfat+a[2].ffat;
			}
			else if((a[1].a3==a[1].cnt)&&(a[2].a3==a[2].cnt)){
				if(abs(a[1].ffat-a[1].sfat)>abs(a[2].ffat-a[2].sfat)) ans=a[1].ffat+a[2].sfat;
				else ans=a[1].sfat+a[2].ffat;
			}
			else ans=a[1].ffat+a[2].ffat;
			cout<<ans<<"\n";
		}
		else if(IF1==0&&IF2==0){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].a3;
			}
			cout<<ans<<"\n";
		}
		else if(IF1==0&&IF3==0){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].a2;
			}
			cout<<ans<<"\n";
		}
		else if(IF2==0&&IF3==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].a1;
			}
			cout<<ans<<"\n";
		}
		else if(IF3==0){
			int ren1=0,ren2=0,ren3=0;
			for(int i=1;i<=n;++i){
				a[i].c1=a[i].a1-a[i].a2;
				if(a[i].a1>a[i].a2) ren1++;
				else if(a[i].a1<a[i].a2) ren2++;
				else ans+=a[i].cnt,ren3++;
			}
			if(ren1>n/2){
				int ab[100005];
				for(int i=1;i<=n;++i){
					ab[i]=a[i].c1;
				}
				sort(ab+1,ab+n+1);
				for(int i=1;i<=n;++i){
					if(ab[i]==0) continue;
					else {
						a[i].cnt=a[i].a2,ren1--,ren2++;
					}
					if(ren1<=n/2) break;
				}
			}
			else if(ren2>n/2){
				int ab[100005];
				for(int i=1;i<=n;++i){
					ab[i]=a[i].c1;
				}
				sort(ab+1,ab+n+1);
				for(int i=1;i<=n;++i){
					if(ab[i]==0) continue;
					else {
						a[i].cnt=a[i].a1,ren2--,ren1++;
					}
					if(ren2<=n/2) break;
				}
			}
			for(int i=1;i<=n;++i){ans+=a[i].cnt;}
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=n;++i){
				ans+=a[i].cnt;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
