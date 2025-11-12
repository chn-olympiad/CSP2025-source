//GZ-S00403 贵阳市第一中学 袁楷伦 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;

struct node{
	int num,dis;
}arr[N];
bool cmp(node a,node b){
	return a.num<b.num;
}
int a[N],b[N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++){
			int tmp=0;
			cin>>a[i]>>b[i]>>c[i];
			tmp=max(a[i],max(b[i],c[i]));
			if(tmp==a[i]){
			 cnt1+=1; 
			}else if(tmp==b[i]){
			 cnt2+=1;
			}else{ 
			 cnt3+=1;
			}
		}
		int cnt=0,sum=0;
		for(int i=1;i<=n/2;i++){
			arr[i].dis=0;
			arr[i].num=0;
		}
		if(cnt1>n/2){
			for(int i=1;i<=n;i++){
				int tmp=max(a[i],max(b[i],c[i]));
				if(tmp==a[i]&&cnt!=n/2){
					arr[++cnt].num=tmp,arr[cnt].dis=i;
					sum+=tmp;
				}else if(tmp==a[i]&&cnt==n/2){
					int tmp1=max(c[i],b[i]),op=0,vis;
					for(int j=1;j<=cnt;j++){
						int tmp2=max(c[arr[j].dis],b[arr[j].dis]);
						if(tmp2+tmp>tmp1+arr[j].num&&tmp2+tmp-tmp1-arr[j].num>op){
							op=tmp2+tmp-tmp1-arr[j].num;
							vis=arr[j].dis;
						}
					}
					if(op==0){
						sum+=tmp1;
					}else{
						sum=sum+op+tmp1;
						arr[vis].num=tmp,arr[vis].dis=i;
					}
				}else{
					sum+=tmp;
				}
			}
		}else if(cnt2>n/2){
			for(int i=1;i<=n;i++){
				int tmp=max(a[i],max(b[i],c[i]));
				if(tmp==b[i]&&cnt!=n/2){
					arr[++cnt].num=tmp,arr[cnt].dis=i;
					sum+=tmp;
				}else if(tmp==b[i]&&cnt==n/2){
					int tmp1=max(a[i],c[i]),op=0,vis;
					for(int j=1;j<=cnt;j++){
						int tmp2=max(a[arr[j].dis],c[arr[j].dis]);
						if(tmp2+tmp>tmp1+arr[j].num&&tmp2+tmp-tmp1-arr[j].num>op){
							op=tmp2+tmp-tmp1-arr[j].num;
							vis=arr[j].dis;
						}
					}
					if(op==0){
						sum+=tmp1;
					}else{
						sum=sum+op+tmp1;
						arr[vis].num=tmp,arr[vis].dis=i;
					}
				}else{
					sum+=tmp;
				}
			}
		}else if(cnt3>n/2){
//			cout<<114514<<endl;
			for(int i=1;i<=n;i++){
				int tmp=max(a[i],max(b[i],c[i]));
				if(tmp==c[i]&&cnt!=n/2){
					arr[++cnt].num=tmp,arr[cnt].dis=i;
					sum+=tmp;
				}else if(tmp==c[i]&&cnt==n/2){
					int tmp1=max(a[i],b[i]),op=0,vis;
					for(int j=1;j<=cnt;j++){
						int tmp2=max(a[arr[j].dis],b[arr[j].dis]);
						if(tmp2+tmp>tmp1+arr[j].num&&tmp2+tmp-tmp1-arr[j].num>op){
							op=tmp2+tmp-tmp1-arr[j].num;
							vis=arr[j].dis;
						}
					}
					if(op==0){
						sum+=tmp1;
					}else{
						sum=sum+op+tmp1;
						arr[vis].num=tmp,arr[vis].dis=i;
					}
				}else{
					sum+=tmp;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				sum+=max(a[i],max(b[i],c[i]));
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
/*
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


1
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

2
10 9 8
4 0 0


*/
