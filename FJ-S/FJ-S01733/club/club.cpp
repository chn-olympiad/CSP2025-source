#include <bits/stdc++.h>
using namespace std;
struct s1{
	int n1,n2,n3;
}a[100001];
struct s2{
	int n1,n2,n3;
}b[100001];
struct s3{
	int n1,n2,n3;
}c[100001];
bool cmp1(s1 a,s1 b){
	return a.n1>b.n1;
}
bool cmp2(s2 a,s2 b){
	return a.n2>b.n2;
}
bool cmp3(s3 a,s3 b){
	return a.n3>b.n3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			b[i].n1=a[i].n1;
			b[i].n2=a[i].n2;
			b[i].n3=a[i].n3;
			c[i].n1=a[i].n1;
			c[i].n2=a[i].n2;
			c[i].n3=a[i].n3;
		}
		stable_sort(a+1,a+n+1,cmp1);
		stable_sort(b+1,b+n+1,cmp2);
		stable_sort(c+1,c+n+1,cmp3);
		if(n==2){
			int m1=(a[1].n1+a[2].n2);
		    int m2=(a[1].n1+a[2].n3);
		    int m3=(a[1].n2+a[2].n1);
		    int m4=(a[1].n2+a[2].n3);
		    int m5=(a[1].n3+a[2].n2);
		    int m6=(a[1].n3+a[2].n1);
		    int ma=max(m1,max(m2,max(m3,max(m4,max(m5,m6)))));
		    cout<<ma<<'\n';
		}
		else if(n>200){
			int sum1=0,sum2=0,sum3=0;
			for(int i=1;i<=n/2;i++){
				sum1+=a[i].n1;
				sum2+=b[i].n2;
				sum3+=c[i].n3;
			}
			cout<<max(sum1,max(sum2,sum3))<<'\n';
		}
		 
	}
}
