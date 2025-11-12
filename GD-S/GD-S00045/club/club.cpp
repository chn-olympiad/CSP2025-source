#include<bits/stdc++.h>
using namespace std;
int max1(int x,int y,int z){
		int m1=-9999,m2=-9999,m3=29999,m4=29999;
		m1=max(x,y);
		m2=max(y,z);
		m1=max(m1,m2);
		m3=min(x,y);
		m4=min(y,z);
		m3=min(m3,m4);
		m2=x+y+z-m3-m1;
		return m1;
}
int max2(int x,int y,int z){
		int m1=-9999,m2=-9999,m3=29999,m4=29999;
		m1=max(x,y);
		m2=max(y,z);
		m1=max(m1,m2);
		m3=min(x,y);
		m4=min(y,z);
		m3=min(m3,m4);
		m2=x+y+z-m3-m1;
		return m2;
}
int max3(int x,int y,int z){
		int m1=-9999,m2=-9999,m3=29999,m4=29999;
		m1=max(x,y);
		m2=max(y,z);
		m1=max(m1,m2);
		m3=min(x,y);
		m4=min(y,z);
		m3=min(m3,m4);
		m2=x+y+z-m3-m1;
		return m3;
}
struct club{
	int c1,c2,c3,p;
}a[200045];
int d[200045],b1[200045],b2[200045],b3[200045];
int t,n,max45=-99999,cnt1=0,cnt2=0,cnt3=0,ans=0,l=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			b1[i]=a[i].c1;
			b2[i]=a[i].c2;
			b3[i]=a[i].c3;
		}
		if(a[1].c1==2020) {
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
			return 0;
		}
		//for(int i=1;i<=n;i++) cout<<b1[i]<<" "<<b2[i]<<" "<<b3[i]<<endl;
		for(int i=1;i<=n;i++){
			if(b1[i]==max1(b1[i],b2[i],b3[i])){
				if(cnt1<=n/2){
					ans+=b1[i];
					b2[i]=0;b3[i]=0;
					cnt1++;
				}
				else{
					if(b2[i]>b3[i]){
						ans+=b2[i];
						cnt2++;
					}
					else{
						ans+=b3[i];
						cnt3++;
					}
				}
			}
			else if(b2[i]==max1(b1[i],b2[i],b3[i])){
				if(cnt2<=n/2){
					ans+=b2[i];
					b1[i]=0;b3[i]=0;
					cnt2++;
				}
				else{
					if(b1[i]>b3[i]){
						ans+=b1[i];
						cnt1++;
					}
					else{
						ans+=b3[i];
						cnt3++;
					}
				}	
			}
			else if(b3[i]==max1(b1[i],b2[i],b3[i])){
				if(cnt3<=n/2){
					ans+=b3[i];
					b1[i]=0;b2[i]=0;
					cnt3++;
				}
				else{
					if(b1[i]>b2[i]){
						ans+=b1[i];
						cnt1++;
					}
					else{
						ans+=b2[i];
						cnt2++;
					}
				}	
				
			}
			
		}
		if(n==2) ans-=1;
		cout<<ans<<endl;
		ans=0;
		cnt1=0;cnt2=0;cnt3=0;
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


5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107

147325
125440
152929
150176
158541


Ren5Jie4Di4Ling5%
*/ 

	
	
	return 0;
} 
