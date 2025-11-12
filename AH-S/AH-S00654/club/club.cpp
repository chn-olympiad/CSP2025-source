#include<bits/stdc++.h>
using namespace std;
struct node{
	int date;
	int num;
};
node a[100005];
node b[100005];
node c[100005];
int n,t;
int vol[100005];
bool cmp(node x,node y){
	return x.date>y.date;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int mid;
		mid=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].date>>b[i].date>>c[i].date;
			a[i].num=i;
			b[i].num=i;
			c[i].num=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int rel,sa,sb,sc;
		rel=0;
		sa=0;
		sb=0;
		sc=0;
		for(int i=1;i<=n;i++){
			int l;
			l=0;
			int ta,tb,tc;
			ta=a[i].date;
			tb=b[i].date;
			tc=c[i].date;
			if(sa<mid&&vol[a[i].num]==0){
				rel+=ta;
				vol[a[i].num]=1;
				sa++;
				l=1;
			 }
			 if(sb<mid){
				if(b[i].num==a[i].num&&l==1){
					if(b[i].date>a[i].date){
						rel+=tb;
						sb++;
						rel-=ta;
						sa--;
						l=2;
					}
				}
				else if(vol[b[i].num]==0){
					rel+=tb;
					sb++;
					vol[b[i].num]=1;
					l=2;
				}
			}
			if(sc<mid){
				if(c[i].num==a[i].num&&l==1){
					if(c[i].date>a[i].date){
						rel+=tc;
						sc++;
						rel-=ta;
						sa--;
					}
				}
				else if(c[i].num==b[i].num&&l==2){
					if(c[i].date>b[i].date){
						rel+=tc;
						sc++;
						rel-=tb;
						sb--;
					}
				}
				else if(vol[c[i].num]==0){
					rel+=tc;
					vol[c[i].num]=1;
					sc++;
				}
			}
			//cout<<a[i].num<<" "<<b[i].num<<" "<<c[i].num<<'\n';
			
		}
		for(int i=1;i<=n;i++)vol[i]=0;
		cout<<rel<<'\n';
	}

	
	return 0;
}
