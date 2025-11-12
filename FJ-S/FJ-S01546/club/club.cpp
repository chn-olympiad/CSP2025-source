#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;
	char s=getchar();
	int bj=0;
	while(s<'0'||s>'9'){
		if(s=='-'){
			bj=1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj){
		x=-x;
	}
}
template<typename T>void write(T x){
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int t,n,jl[5],sum=0;
struct sj{
	int z1,z2,z3,h1,h2,h3;
}a[100005];
bool px(sj x,sj y){
	if(x.z1==y.z1){
		if(x.z2==y.z2){
			return x.z3>y.z3;
		}
		return x.z2>y.z2;
	}
	return x.z1>y.z1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		jl[1]=0;
		jl[2]=0;
		jl[3]=0;
		sum=0;
		read(n);
		for(int i=1,a1,b,c;i<=n;i++){
			read(a1),read(b),read(c);
			if(a1>=b&&b>=c){
				a[i].z1=a1;a[i].z2=b;a[i].z3=c;
				a[i].h1=1;a[i].h2=2;a[i].h3=3;
				continue;
			}
			if(a1>=c&&c>=b){
				a[i].z1=a1;a[i].z2=c;a[i].z3=b;
				a[i].h1=1;a[i].h2=3;a[i].h3=2;
				continue;
			}
			if(b>=a1&&a1>=c){
				a[i].z1=b;a[i].z2=a1;a[i].z3=c;
				a[i].h1=2;a[i].h2=1;a[i].h3=3;
				continue;
			}
			if(b>=c&&c>=a1){
				a[i].z1=b;a[i].z2=c;a[i].z3=a1;
				a[i].h1=2;a[i].h2=3;a[i].h3=1;
				continue;
			}
			if(c>=b&&b>=a1){
				a[i].z1=c;a[i].z2=b;a[i].z3=a1;
				a[i].h1=3;a[i].h2=2;a[i].h3=1;
				continue;
			}
			if(c>=a1&&a1>=b){
				a[i].z1=c;a[i].z2=a1;a[i].z3=b;
				a[i].h1=3;a[i].h2=1;a[i].h3=2;
				continue;
			}
		}
		sort(a+1,a+n+1,px);
		for(int i=1;i<=n;i++){
			if(jl[a[i].h1]<n/2){
				sum+=a[i].z1;
				jl[a[i].h1]++;
			}else if(jl[a[i].h2]<n/2){
				sum+=a[i].z2;
				jl[a[i].h2]++;
			}else{
				sum+=a[i].z3;
				jl[a[i].h3]++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
