#include <bits/stdc++.h>
using namespace std;
int t,n,p,o,i,ans,dy,de,ds;
struct student{
	int q,w,e,d;
}a[1000000];
bool cmp(student a,student b){
	return a.d<b.d;
}
bool cmpp(student a,student b){
	return min(a.w,a.e)<min(b.w,b.e);
}
bool cmppp(student a,student b){
	return min(a.q,a.e)<min(b.q,b.e);
}
bool cmpppp(student a,student b){
	return min(a.w,a.q)<min(b.w,b.q);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		dy=0;
		de=0;
		ds=0;
		ans=0;
		for(int j=0;j<n;j++){
			cin>>p>>o>>i;
			if(max(p,max(o,i))==p){
				ans+=p;
				a[j].q=p;
				a[j].w=p-o;
				a[j].e=p-i;
				a[j].d=1;
				dy++;
			}
			if(max(p,max(o,i))==o){
				ans+=o;
				a[j].q=o-p;
				a[j].w=o;
				a[j].e=o-i;
				a[j].d=2;
				de++;
			}
			if(max(p,max(o,i))==i){
				ans+=i;
				a[j].q=i-p;
				a[j].w=i-o;
				a[j].e=i;
				a[j].d=3;
				ds++;
			}	
		}
		while(dy>n/2||de>n/2||ds>n/2){
			sort(a,a+n,cmp);
			sort(a,a+dy,cmpp);
			if(dy==0){
				sort(a+dy,a+dy+de,cmppp);
			}else sort(a+dy,a+dy+de,cmppp);
			
			if(de==0&&dy==0){
				sort(a,a+ds,cmpppp);
			}else if(de==0||dy==0){
				sort(a+dy+de,a+dy+de+ds,cmpppp);
			}
			else sort(a+de+dy,a+de+dy+ds,cmpppp);
			for(int i=1;i<=3;i++){
				if(dy<=n/2&&i==1||de<=n/2&&i==2||ds<=n/2&&i==3){
					continue;
				}else{
					if(i==1){
						if(a[0].w<a[0].e){
							a[0].d=2;
							ans-=a[0].q;
							dy--;
							
							ans+=a[0].q-a[0].w;
							de++;
							a[0].w=a[0].q-a[0].w;
						}else{
							a[0].d=3;
							ans-=a[0].q;
							dy--;
							ans+=a[0].q-a[0].w;
							de++;
							a[0].w=a[0].q-a[0].w;
						}
					}
					if(i==2){
						if(a[dy].q<a[dy].e){
							a[dy].d=1;
							ans-=a[dy].w;
							de--;
							ans+=a[dy].q-a[dy].w;
							dy++;
							a[dy-1].q=a[dy-1].q-a[dy-1].w;
						}else{
							a[dy].d=3;
							ans-=a[dy].w;
							de--;
							ans+=a[dy].w-a[dy].e;
							
							ds++;
							a[dy].e=a[dy].w-a[dy].e;
						}
					}
					if(i==3){
						if(a[de+dy].q<a[de+dy].w){
							a[de+dy].d=1;
							ans-=a[de+dy].e;
							ds--;
							ans+=a[de+dy].e-a[de+dy].q;
							dy++;
							a[de+dy-1].q=a[de+dy-1].e-a[de+dy-1].q;
						}else{
							a[de+dy].d=2;
							ans-=a[de+dy].e;
							ds--;
							ans+=a[de+dy].e-a[de+dy].w;
							de++;
							a[de+dy-1].w=a[de+dy-1].e-a[de+dy-1].w;
						}
					}
				}
			}
		}
	
		cout<<ans<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}