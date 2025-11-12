#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a1;
	int a2;
	int a3;
	int maxa;
	int ai;
}a[100005];
bool cmp(node x,node y){
	return x.maxa>y.maxa;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
	if(n==2){
		int a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		int ma=max(a,max(b,c));
		if(ma==a)ma+=max(e,f);
		else if(ma==b)ma+=max(d,f);
		else if(ma==c)ma+=max(d,e);
		int ma2=max(d,max(e,f));
		if(ma2==d)ma2+=max(b,c);
		else if(ma2==e)ma2+=max(a,c);
		else if(ma2==f)ma2+=max(a,b);
		cout<<max(ma,ma2)<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].maxa=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].maxa==a[i].a1){
				if(a[i].a2>a[i].a3)a[i].ai=123;
				else a[i].ai=132;
			}
			else if(a[i].maxa==a[i].a2){
				if(a[i].a1>a[i].a3)a[i].ai=213;
				else a[i].ai=231;
			}
			else{
				if(a[i].a1>a[i].a2)a[i].ai=312;
				else a[i].ai=321;
			}
		}
		sort(a,a+n,cmp);
		int d=0,e=0,f=0,index=0;
		long long ans=0;
		while(index<n){
			if(a[index].ai/100==1&&d<n/2){
				d++;
				ans+=a[index].a1;
			}
			if(a[index].ai/100==2&&e<n/2){
				e++;
				ans+=a[index].a2;
			}
			if(a[index].ai/100==3&&f<n/2){
				f++;
				ans+=a[index].a3;
			}
			index++;
		}
		cout<<ans<<endl;
	}
	}
	return 0;
} 
