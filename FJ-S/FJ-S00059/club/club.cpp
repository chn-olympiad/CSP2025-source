#include<bits/stdc++.h>
using namespace std;
long long t,n,s;
struct yu{
	long long x,y,z;
}a[100005];
int cnm(long long a1,long long a2,long long a3,long long aa){
	s=max(s,aa);
	if(a1+a2+a3==n){
		return 0;
	}
	if(a1<(n/2)){cnm(a1+1,a2,a3,aa+a[a1+a2+a3+1].x);}
	if(a2<(n/2)){cnm(a1,a2+1,a3,aa+a[a1+a2+a3+1].y);}
	if(a3<(n/2)){cnm(a1,a2,a3+1,aa+a[a1+a2+a3+1].z);}
}
int cnm2(long long a1,long long a2,long long a3,long long aa){
	s=max(s,aa);
	if(a1+a2+a3==n){
		return 0;
	}
	if(a1<(n/2)){cnm(a1+1,a2,a3,aa+a[a1+a2+a3+1].x);}
	if(a2<(n/2)){cnm(a1,a2+1,a3,aa+a[a1+a2+a3+1].y);}
}
bool cmp(yu a,yu b){
	return a.y>b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool f1=true,f2=true;
		long long s1=0,s2=0,s3=0,ss=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x!=0) f1=false;
			if(a[i].z!=0) f2=false;
		}
		if(f1&&f2){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				s+=a[i].y;
			}
		}else if(f2){
			cnm2(s1,s2,s3,ss);
		}
		else{
			cnm(s1,s2,s3,ss);
		}
		cout<<s<<endl;
		s=0;
	}
	return 0;
}
