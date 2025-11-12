#include<bits/stdc++.h>
using namespace std;
struct RQ{
	long long a,i;
}a1[100010],a2[100010],a3[100010];
int cmp(RQ x,RQ y){
	if(x.a>y.a) return 1;
	return 0;
}
long long f[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(f,0,sizeof(f));
		long long n,ss=0,s2=0,s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i].a>>a2[i].a>>a3[i].a;
			a1[i].i=i;
			a2[i].i=i;
			a3[i].i=i;
			if(a2[i].a==0) s2++;
			if(a3[i].a==0) s3++;
		}
		if(s2==n&&s3==n){
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++) ss+=a1[i].a;
			cout<<ss<<endl;
			continue;
		}
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		long long s=0,t1=0,t2=0,t3=0,m1=1,m2=1,m3=1,fm;
		for(int i=1;i<=n;i++){
			long long ma=0,mi;
			while(f[a1[m1].i]==1&&m1<n) m1++;
			if(a1[m1].a>ma){
				f[a1[m1].i]=1;
				fm=1;
				ma=a1[m1].a;
				mi=1;
				t1++;
				m1++;
			}
			if(a2[m2].i==a1[m1-1].i&&a2[m2].a>ma){
				f[a2[m2].i]=1;
				fm=2;
				if(mi==1){
					t1--;
					m1--;
					f[a1[m1].i]=0;
				}
				ma=a2[m2].a;
				mi=2;
				t2++;
				m2++;
			}
			else{
				while(f[a2[m2].i]==1&&m2<n) m2++;
				if(a2[m2].a>ma){
					f[a2[m2].i]=1;
					fm=2;
					if(mi==1){
						t1--;
						m1--;
						f[a1[m1].i]=0;
					}
					ma=a2[m2].a;
					mi=2;
					t2++;
					m2++;
				}
			}
			if(a3[m3].i==a2[m2-1].i&&a3[m3].a>ma){
				ma=a3[m3].a;
				if(mi==1){
					t1--;
					f[a1[m1].i]=0;
					m1--;
				}	
				if(mi==2){
					t2--;
					f[a2[m2].i]=0;
					m2--;
				}
				f[a3[m3].i]=1;
				t3++;
				m3++;
			} 
			else{
				while(f[a3[m3].i]==1&&m3<n) m3++;
				if(a3[m3].a>ma){
					ma=a3[m3].a;
					if(mi==1){
						t1--;
						f[a1[m1].i]=0;
						m1--;
					}	
					if(mi==2){
						t2--;
						f[a2[m2].i]=0;
						m2--;
					}
					f[a3[m3].i]=1;
					t3++;
					m3++;
				}
			}
			s+=ma;
			if(t1==n/2) memset(a1,-1,sizeof(a1)); 
			if(t2==n/2) memset(a2,-1,sizeof(a2));
			if(t3==n/2) memset(a3,-1,sizeof(a3));
		}
		cout<<s<<endl;
	}
	return 0;
}

