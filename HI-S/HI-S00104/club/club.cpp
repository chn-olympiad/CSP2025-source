#include<bits/stdc++.h>
using namespace std;
struct qp{
	int x,y,z;
	int ma,mi,th;
	int num1,num2,num3;
}a[10000000];
int club[10];
bool cmp(qp s1,qp s2){
	return(s1.ma>s2.ma||(s1.mi<s2.mi&&s1.ma==s2.ma));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int q;cin>>q;
	while(q){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			a[i].x=0;
			a[i].y=0;
			a[i].z=0;
			a[i].ma=0;
			a[i].mi=0;
			a[i].num1=0;
			a[i].th=0;
			a[i].num2=0;
			a[i].num3=0;	
		}
		for(int i=1;i<=n;i++){
			int q,w,e,qw=0,wwe=0;cin>>q>>w>>e;
			
			qw=min(q,w);
			a[i].mi=min(qw,e);
			a[i].x=q-a[i].mi;
			a[i].y=w-a[i].mi;
			a[i].z=e-a[i].mi;
			wwe=max(a[i].x,a[i].y);
			a[i].ma=max(a[i].z,wwe);
			if(a[i].ma==a[i].x) a[i].num1=1;
			else if(a[i].ma==a[i].y) a[i].num1=2;
			else if(a[i].ma==a[i].z) a[i].num1=3;
			
			if(a[i].x!=a[i].ma&&a[i].x!=0){
				a[i].th=a[i].x;
				a[i].num2=1;
			}else if(a[i].y!=a[i].ma&&a[i].y!=0){
				a[i].th=a[i].y;
				a[i].num2=2;
			}else if(a[i].z!=a[i].ma&&a[i].z!=0){
				a[i].th=a[i].z;
				a[i].num2=3;
			}
			for(int j=1;j<=3;j++){
				if(j!=a[i].num1&&j!=a[i].num2){
					a[i].num3=j;
					break;
				}
			}
		}int s=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(club[a[i].num1]<n/2){
				s=s+a[i].ma+a[i].mi;
				club[a[i].num1]++;	
			}else if(club[a[i].num2]<n/2){
				s=s+a[i].th+a[i].mi;
				club[a[i].num2]++;
			}else if(club[a[i].num3]<n/2){
				s=s+a[i].mi;
				club[a[i].num3]++;
			}
		}cout<<s<<endl;
		s=0;
		for(int i=1;i<=3;i++){
			club[i]=0;
		}
		q--;
	}

	return 0;
}
