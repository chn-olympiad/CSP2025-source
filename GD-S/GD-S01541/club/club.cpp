#include<bits/stdc++.h>
using namespace std;
//#define ll long long
	int t,n,cr1,cr2,cr3,st1[100003],st2[100001],st3[100003];
	struct s{int d1,d2,d3,mx;}a[100003];
bool cmpa(s a,s b){
	return a.d1>b.d1;
}
bool cmp1(int x,int y){
	int ma=min(a[x].d1-a[x].d2,a[x].d1-a[x].d3),mb=min(a[y].d1-a[y].d2,a[y].d1-a[y].d3);
	return ma<mb;
}
bool cmp2(int x,int y){
	int ma=min(a[x].d2-a[x].d1,a[x].d2-a[x].d3),mb=min(a[y].d2-a[y].d1,a[y].d2-a[y].d3);
	return ma<mb;
}
bool cmp3(int x,int y){
	int ma=min(a[x].d3-a[x].d2,a[x].d3-a[x].d1),mb=min(a[y].d3-a[y].d2,a[y].d3-a[y].d1);
	return ma<mb;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;cr1=0;cr2=0;cr3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].mx=max(a[i].d1,max(a[i].d2,a[i].d3));
		}
		long long ans=0;int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			ans+=a[i].mx;
			if(a[i].d1==a[i].mx)c1++,st1[++cr1]=i;
			else if(a[i].d2==a[i].mx)c2++,st2[++cr2]=i;
			else c3++,st3[++cr3]=i;
		}
		if(c1>n/2){
			sort(st1+1,st1+cr1+1,cmp1);int k=c1-n/2;
			for(int i=1;i<=k;i++){
				ans-=min(a[st1[i]].d1-a[st1[i]].d3,a[st1[i]].d1-a[st1[i]].d2);
			}
		}
		else if(c2>n/2){
			sort(st2+1,st2+cr2+1,cmp2);int k=c2-n/2;
			for(int i=1;i<=k;i++){
				ans-=min(a[st2[i]].d2-a[st2[i]].d3,a[st2[i]].d2-a[st2[i]].d1);
			}
		}
		else if(c3>n/2){
			sort(st3+1,st3+cr3+1,cmp3);int k=c3-n/2;
			for(int i=1;i<=k;i++){
				ans-=min(a[st3[i]].d3-a[st3[i]].d1,a[st3[i]].d3-a[st3[i]].d2);
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
