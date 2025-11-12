#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,n,f[N],cnt,k[N],cu,fd,a[5];
struct ABC{
	int a,b,c,ma,k,x;
}s[N];
struct FULE{
	int a,b;
}A[5];
bool cmp(ABC s1,ABC s2){
	if(s1.ma!=s2.ma)
		return s1.ma>s2.ma;
	else
		return max(max(s1.a,s1.b),s1.c)>max(max(s2.a,s2.b),s2.c);
}
bool cmpp(FULE A1,FULE A2){
		return A1.a<A2.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cnt=0;
		f[1]=0;
		f[2]=0;
		f[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			A[1].a=s[i].a;
			A[2].a=s[i].b;
			A[3].a=s[i].c;
			for(int j=1;j<=3;j++)
				A[j].b=j;
			sort(A+1,A+4,cmpp);
			s[i].ma=A[3].a-A[2].a;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			A[1].a=s[i].a;
			A[2].a=s[i].b;
			A[3].a=s[i].c;
			for(int j=1;j<=3;j++)
				A[j].b=j;
			int st=0;
			sort(A+1,A+4,cmpp);
			if(A[3].b!=A[2].b) st=1;
			if(f[A[3].b]+st<=n/2){
				cnt+=A[3].a;
				f[A[3].b]+=st;
			}
			else{
				cnt+=A[2].a;
				f[A[2].b]+=st;
			}
		}
		cu++;
		k[cu]=cnt;
	}
	for(int i=1;i<=cu;i++)
		cout<<k[i]<<endl;
    return 0;
}
