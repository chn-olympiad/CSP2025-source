#include<bits/stdc++.h>
using namespace std;
long long t,n,s1,s2,s3,sb,fa1,fa2,fa3,ans=0;
struct node{
	long long a,b,c,z;
}a[100005],a1[100005],a2[100005],a3[100005],b[100005];
bool cmp1(node p,node q){
	return p.a>q.a;
}
bool cmp2(node p,node q){
	return p.b>q.b;
}
bool cmp3(node p,node q){
	return p.c>q.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s1=0;
		s2=0;
		s3=0;
		sb=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a){
				a1[++s1]=a[i];
				a1[s1].z=i;
			}
			else if(max(a[i].b,a[i].c)==a[i].b){
				a2[++s2]=a[i];
				a2[s2].z=i;
			}
			else{
				a3[++s3]=a[i];
				a3[s3].z=i;
			}
		}
		sort(a1+1,a1+1+s1,cmp1);
		sort(a2+1,a2+1+s2,cmp2);
		sort(a3+1,a3+1+s3,cmp3);
		if(s1>n/2){
			for(int i=n/2+1;i<=s1;i++){
				b[++sb]=a1[i];
			}
			fa1=0;
		}
		else fa1=1;
		if(s2>n/2){
			for(int i=n/2+1;i<=s2;i++){
				b[++sb]=a2[i];
			}
			fa2=0;
		}
		else fa2=1;
		if(s3>n/2){
			for(int i=n/2+1;i<=s3;i++){
				b[++sb]=a3[i];
			}
			fa3=0;
		}
		else fa3=1;
		for(int i=1;i<=sb;i++){
			if(fa1 && fa2){
				if(max(b[i].a,b[i].b)==b[i].a){
					a1[++s1]=b[i];
					a1[s1].z=i;
				}
				else{
					a2[++s2]=b[i];
					a2[s2].z=i;
				}
			}
			else if(fa3 && fa2){
				if(max(b[i].c,b[i].b)==b[i].c){
					a3[++s3]=b[i];
					a3[s3].z=i;
				}
				else{
					a2[++s2]=b[i];
					a2[s2].z=i;
				}
			}
			else if(fa1 && fa3){
				if(max(b[i].a,b[i].c)==b[i].a){
					a1[++s1]=b[i];
					a1[s1].z=i;
				}
				else{
					a3[++s3]=b[i];
					a3[s3].z=i;
				}
			}
			else if(fa1==1){
				a1[++s1]=b[i];
				a1[s1].z=i;
			}
			else if(fa2==1){
				a2[++s2]=b[i];
				a2[s2].z=i;
			}
			else{
				a3[++s3]=b[i];
				a3[s3].z=i;
			}
		}
		sort(a1+1,a1+1+s1,cmp1);
		sort(a2+1,a2+1+s2,cmp2);
		sort(a3+1,a3+1+s3,cmp3);
		sb=0;
		if(fa1 && fa2){
			if(s1>n/2){
				for(int i=n/2+1;i<=s1;i++){
					b[++sb]=a1[i];
				}
				fa1=0;
			}
			else fa1=1;
			if(s2>n/2){
				for(int i=n/2+1;i<=s2;i++){
					b[++sb]=a2[i];
				}
				fa2=0;
			}
			else fa2=1;
			for(int i=1;i<=sb;i++){
				if(fa1){
					a1[++s1]=b[i];
					a1[s1].z=i;
				}
				else{
					a2[++s2]=b[i];
					a2[s2].z=i;
				}
			}
		}
		else if(fa3 && fa2){
			if(s3>n/2){
				for(int i=n/2+1;i<=s3;i++){
					b[++sb]=a3[i];
				}
				fa3=0;
			}
			else fa3=1;
			if(s2>n/2){
				for(int i=n/2+1;i<=s2;i++){
					b[++sb]=a2[i];
				}
				fa2=0;
			}
			else fa2=1;
			for(int i=1;i<=sb;i++){
				if(fa3){
					a3[++s3]=b[i];
					a3[s3].z=i;
				}
				else{
					a2[++s2]=b[i];
					a2[s2].z=i;
				}
			}
		}
		else if(fa1 && fa3){
			if(s1>n/2){
				for(int i=n/2+1;i<=s1;i++){
					b[++sb]=a1[i];
				}
				fa1=0;
			}
			else fa1=1;
			if(s3>n/2){
				for(int i=n/2+1;i<=s3;i++){
					b[++sb]=a2[i];
				}
				fa3=0;
			}
			else fa3=1;
			for(int i=1;i<=sb;i++){
				if(fa1){
					a1[++s1]=b[i];
					a1[s1].z=i;
				}
				else{
					a3[++s3]=b[i];
					a3[s3].z=i;
				}
			}
		}
		for(int i=1;i<=n/2;i++){
			ans+=a1[i].a;
		}
		for(int i=1;i<=n/2;i++){
			ans+=a2[i].b;
		}
		for(int i=1;i<=n/2;i++){
			ans+=a3[i].c;
		}
		cout<<ans<<endl;
	}
	return 0;
}

