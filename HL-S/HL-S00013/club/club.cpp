#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][7],dp[N];
struct node{
	int mx;
	int num;
	int pos;
	int ans;
}m[N];
bool cmp(node x,node y){
	return x.mx>y.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int cnt=0,q=0,w=0,e=0,x=n/2;
		for(int i=1;i<=n;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
			dp[i]=0;
			m[i].mx=0;
			m[i].num=0;
			m[i].pos=0;
			m[i].ans=0;
		}
		int c=0,v=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) c++;
			if(a[i][3]!=0) v++;
			m[i].mx=max({a[i][1],a[i][2],a[i][3]});
			if(m[i].mx==a[i][1]){
				m[i].pos=1;
			} 
			else if(m[i].mx==a[i][2]){
				m[i].pos=2;
			} 
			else if(m[i].mx==a[i][3]){
				m[i].pos=3;
			} 
			m[i].num=i;
		}
		if(c!=0&&v!=0){
			for(int i=1;i<=n;i++){
				dp[i]=a[i][1];
			}
			sort(dp+1,dp+1+n);
			for(int i=n;i>=x;i--){
				cnt+=dp[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if((abs(a[i][1]-a[i][2])>abs(a[i][2]-a[i][3]))){
				if(a[i][1]>=a[i][2]&&q!=x){
					cnt+=a[i][1];
					dp[i]=a[i][1];
					q++;
				}
				else if(a[i][1]>=a[i][2]&&q==x){
					if(a[i][2]<=a[i][3]){
						cnt+=a[i][3];
						dp[i]=a[i][3];
						e++;
					}
					else{
						cnt+=a[i][2];
						dp[i]=a[i][2];
						w++;
					}
				}
				else if(a[i][1]<a[i][2]&&w!=x){
					cnt+=a[i][2];
					dp[i]=a[i][2];
					w++;
				}
				else if(a[i][1]<a[i][2]&&w==x){
					if(a[i][1]>=a[i][3]){
						cnt+=a[i][1];
						dp[i]=a[i][1];
						q++;
					}
					else{
						cnt+=a[i][3];
						dp[i]=a[i][3];
						e++;
					}
				}
			}
			else{
				if(a[i][3]>=a[i][2]&&e!=x){
					cnt+=a[i][3];
					dp[i]=a[i][3];
					e++;
				}
				else if(a[i][3]>=a[i][2]&&e==x){
					if(a[i][2]<=a[i][1]){
						cnt+=a[i][1];
						dp[i]=a[i][1];
						q++;
					}
					else{
						cnt+=a[i][2];
						dp[i]=a[i][2];
						w++;
					}
				}
				else if(a[i][3]<a[i][2]&&w!=x){
					cnt+=a[i][2];
					dp[i]=a[i][2];
					w++;
				}
				else if(a[i][3]<a[i][2]&&w==x){
					if(a[i][1]>=a[i][3]){
						cnt+=a[i][1];
						dp[i]=a[i][1];
						q++;
					}
					else{
						cnt+=a[i][3];
						dp[i]=a[i][3];
						e++;
					}
				}
			}
		}
		sort(m+1,m+1+n,cmp);
		int note=0;
		for(int l=1;l<=n;l++){
			if(m[l].pos==1){
			    m[l].ans=q;
			    note=1;
			} 
			if(m[l].pos==2){
				m[l].ans=w;
				note=2;
			} 
			if(m[l].pos==3){
				m[l].ans=e;
				note=3;
			} 
			if(a[m[l].num][m[l].pos]<dp[m[l].num]||m[l].ans==x){
				continue;
			} 
			cnt=cnt-dp[m[l].num]+m[l].mx;
			if(note==1) q++;
			else if(note==2) w++;
			else e++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*Fuck CCF !!!
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
*/
