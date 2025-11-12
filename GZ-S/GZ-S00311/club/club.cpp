//GZ-S00311  ◊Ò“ÂÀƒ≥ı  Õı≈‡Ïı 
#include<bits/stdc++.h>
using namespace std;
int n,t,a2[100001],b2[100001],c2[100001],a3,b3,c3,ans;
struct v1{
	int a[4];
	int x[4];
	int b=1;
}a1[100001];
bool st(v1 a,v1 b){
	if(a.a[a.x[1]]==b.a[b.x[1]]){
		if(a.a[a.x[2]]==b.a[b.x[2]]){
			return a.a[a.x[3]]>b.a[b.x[3]];
		}
		return a.a[a.x[2]]>b.a[b.x[2]];
	}
	return a.a[a.x[1]]>b.a[b.x[1]];
	
}
void choss (int i,int m){
	
	if(a1[i].x[a1[i].b]==1){
		if(a3+1>=n/2+1){
			for(int j=1;j<=a3;j++){//
				if(a1[i].a[1]>a1[a2[j]].a[1]){

					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					a2[j]=i;
					break;
				}
				if(a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b]]-a1[i].a[a1[i].x[a1[i].b]]&&a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>0){
					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					a2[j]=i;
					break;
				}
			}
			a1[i].b++;
			choss(i,a1[i].b);
		}
		else{
			a3++;
			a2[a3]=i;
//			ans+=a1[a2[a3]].a[a1[a2[a3]].x[a1[i].b]];
		}			
	}
	
	
	
	if(a1[i].x[a1[i].b]==2){
		if(b3+1>=n/2+1){
			for(int j=1;j<=a3;j++){
				if(a1[i].a[2]>a1[a2[j]].a[2]){
//					ans-=a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b]];
//					ans+=a1[i].a[a1[i].x[a1[i].b]];
					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					b2[j]=i;
					break;
				}
				if(a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b]]-a1[i].a[a1[i].x[a1[i].b]]&&a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>0){
					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					a2[j]=i;
					break;
				}
			}
			a1[i].b++;
			choss(i,a1[i].b);
		}
		else{
			b3++;
			b2[b3]=i;
//			ans+=a1[a2[a3]].a[a1[a2[a3]].x[a1[i].b]];
		}
	}
	
	
	
	if(a1[i].x[a1[i].b]==3){
		if(c3+1>=n/2+1){
			for(int j=1;j<=a3;j++){
				if(a1[i].a[3]>a1[a2[j]].a[3]){
//					ans-=a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b]];
//					ans+=a1[i].a[a1[i].x[a1[i].b]];
					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					c2[j]=i;
					break;
				}
				if(a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b]]-a1[i].a[a1[i].x[a1[i].b]]&&a1[a2[j]].a[a1[a2[j]].x[a1[a2[j]].b+1]] - a1[i].a[a1[i].x[a1[i].b+1]]>0){
					a1[a2[j]].b++;
					choss(a2[j],a1[a2[j]].b);
					a2[j]=i;
					break;
				}
			}
			
			a1[i].b++;
			choss(i,a1[i].b);
		}
		else{
			c3++;
			c2[c3]=i;
//			ans+=a1[a2[a3]].a[a1[a2[a3]].x[a1[i].b]];
		}
	}
}
void maxn(int i){
	if(a1[i].a[1]>=a1[i].a[2]&&a1[i].a[1]>=a1[i].a[3]){
		a1[i].x[1]=1;
		if(a1[i].a[2]>=a1[i].a[3]){
			a1[i].x[2]=2;
			a1[i].x[3]=3;
		}
		if(a1[i].a[2]<a1[i].a[3]){
			a1[i].x[2]=3;
			a1[i].x[3]=2;
		}
	}
	if(a1[i].a[2]>a1[i].a[1]&&a1[i].a[2]>=a1[i].a[3]){
		a1[i].x[1]=2;
		if(a1[i].a[1]>=a1[i].a[3]){
			a1[i].x[2]=1;
			a1[i].x[3]=3;
		}
		if(a1[i].a[1]<a1[i].a[3]){
			a1[i].x[2]=3;
			a1[i].x[3]=1;
		}
	}
	if(a1[i].a[3]>a1[i].a[2]&&a1[i].a[3]>a1[i].a[1]){
		a1[i].x[1]=3;
		if(a1[i].a[1]>=a1[i].a[2]){
			a1[i].x[2]=1;
			a1[i].x[3]=2;
		}
		if(a1[i].a[1]<a1[i].a[2]){
			a1[i].x[2]=2;
			a1[i].x[3]=1;
		}
	}
}
int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=1;v<=t;v++){
		a3=0;b3=0;c3=0;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i].a[1]>>a1[i].a[2]>>a1[i].a[3];
			a1[i].b=1;
			maxn(i);
		}
		sort(a1+1,a1+1+n,st);
//		for(int i=1;i<=n;i++){
//			cout<<a1[i].a[a1[i].x[2]]<<" "<<a1[i].x[2]<<"     ";
//		}
		for(int i=1;i<=n;i++){
			if(a1[1].a[1]==a1[i].a[2]&&a1[i].a[2]==a1[i].a[3]){
				ans+=a1[i].a[1];
				continue;
			}
			choss(i,1);
		}
		for(int i=1;i<=a3;i++){
			ans+=a1[a2[i]].a[1];
//			cout<<a1[a2[i]].a[1]<<"a ";
		}
		for(int i=1;i<=b3;i++){
			ans+=a1[b2[i]].a[2];
//			cout<<a1[b2[i]].a[2]<<"b ";
		}
		for(int i=1;i<=c3;i++){
			ans+=a1[c2[i]].a[3];
//			cout<<a1[c2[i]].a[3]<<"c ";
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
