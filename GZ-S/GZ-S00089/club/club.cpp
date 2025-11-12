//GZ-S00089 贵阳市第十八中学 吴沁堂
#include<bits/stdc++.h>
using namespace std;
int T,n,r1=0,r2=0,r3=0,sum1,sum2,sum3,p,c1[1000000],c2[1000000],c3[1000000],f1[1000000],f2[1000000],f3[1000000];
long long sum=0;
struct my {
	int m1;
	int m2;
	int m3;
	int id;
	int z;

} a[1000000];
bool cmp(int a,int b) {
	return a<b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		r1=0;
		r2=0;
		r3=0;
		int mi1=9999999;
		int mi2=9999999;
		int mi3=9999999;
		int j1,j2,j3;
		int q1,q2,q3;
		
		sum=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].m1>>a[i].m2>>a[i].m3;

			p=max(a[i].m1,max(a[i].m2,a[i].m3));
			if(p==a[i].m1) {
				r1++;
				c1[r1]==a[i].m1;
				if(a[i].m1-max(a[i].m2,a[i].m3)<mi1) {
					mi1=a[i].m1-max(a[i].m2,a[i].m3);
					q1=r1;
					j1=i;
					

				}
				if(r1>n/2) {
					if(a[j1].m1!=99999999&&f1[j1]==0)
					p-=a[j1].m1,f1[j1]==1;
					a[j1].m1=99999999;
					p+=max(a[j1].m2,a[j1].m3);
					c1[q1]=99999999;
					for(int j=1; j<=r1; j++) {
						if(a[j].m1-max(a[j].m2,a[j].m3)<mi1) {
							mi1=a[j].m1-max(a[j].m2,a[j].m3);
							
							q1=j;


						}
					}
				}


			}

			if(p==a[i].m2) {
				r2++;
				c2[r2]==a[i].m2;
				if(a[i].m2-max(a[i].m1,a[i].m3)<mi2) {
					mi2=a[i].m2-max(a[i].m1,a[i].m3);
					q1=r1;
					j1=i;

				}
				if(r2>n/2) {
				if(a[j2].m2!=99999999&&f2[j2]==0)
				p-=a[j2].m2,f2[j2]==1;
					a[j1].m2=99999999;
					p+=max(a[j1].m1,a[j1].m3);
					c2[q2]=99999999;
					for(int j=1; j<=r2; j++) {
						if(a[j].m2-max(a[j].m1,a[j].m3)<mi2) {
							mi2=a[j].m2-max(a[j].m1,a[j].m3);
							q2=j;


						}
					}
				}


			}


			if(p==a[i].m3) {
				r3++;
				c3[r3]==a[i].m3;
				if(a[i].m3-max(a[i].m2,a[i].m3)<mi3) {
					mi3=a[i].m3-max(a[i].m2,a[i].m3)<mi3;
					q1=r1;
					j1=i;

				}
				if(r3>n/2) {
					if(a[j3].m3!=99999999&&f3[j3]==0)
					p-=a[j3].m3,f3[j3]==1;
					a[j3].m3=99999999;
					p+=max(a[j3].m2,a[j3].m1);
					c3[q3]=99999999;
					for(int j=1; j<=r3; j++) {
						if(a[j].m3-max(a[j].m1,a[j].m2)<mi3) {
							mi3=a[j].m3-max(a[j].m1,a[j].m2);
							q3=j;


						}
					}
				}


			}

			sum+=p;


		}

cout<<sum<<' '; 
	}



	return 0;
}
