#include<bits/stdc++.h>
using namespace std;
int t,n,h;
struct club{
	int cl;
	int man;
};
struct st{
	club q[4];
};
bool cmp(club a,club b){
	if(a.man<b.man){
		return 0;
	}
	return 1;
}
int ans(int a,st p[]){
	int sum,l[4]={0};
	for(int i=1;i<=a;i++){
		sort(p[i].q+1,p[i].q+4,cmp);
	}
	for(int i=1;i<=a;i++){
		sum+=p[i].q[1].man;
		l[p[i].q[1].cl]++;
	}
	for(int i=1;i<=3;i++){
		while(l[i]>h){
			int minx=1000000;
			int huan=0,w=0;
			for(int j=1;j<=a;j++){
				if(p[j].q[1].cl==i){
					w=p[j].q[1].man-p[j].q[2].man;
					if(minx>w and w>=0){
						minx=w;
						huan=j;
					}
				}
				}
				l[p[huan].q[1].cl]--;
				l[p[huan].q[2].cl]++;
				swap(p[huan].q[1],p[huan].q[2]);
				sum-=minx;
				i=1;
		}
	}
	return sum;
	
}
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		h=n/2;
		st a[n+2];
		for(int j=1;j<=n;j++){
			for(int x=1;x<=3;x++){
				cin>>a[j].q[x].man;
				a[j].q[x].cl=x;
			}
		}
		cout<<ans(n,a)<<endl; 
	}
	return 0;
 } 
