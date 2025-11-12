#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+6;
ll T;
bool pd=0;
ll n,a[N][4];
ll ans=0;
ll num1=0,num2=0,num3=0;//每个部门人数 
void init(){
	ans=n=num1=num2=num3=pd=0;
	cin>>n;
	for(ll i = 1;i <= n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]>0||a[i][3]>0){
			pd=1;
		}
	}
}
void work2(){
	ll maxn=0;
	for(ll i = 0;i <= n-1;++i){
		maxn+=2*(ll)(pow(3,i));
	}
//	cout << maxn << endl;
	for(ll i = 0;i <= maxn;++i){
		ll ls=0;
		ll dq=i;
		string s;
		while(dq>0){
		//	cout << dq << endl;
			if(dq%3==0){
				s="0"+s;
			}
			else if(dq%3==1){
				s="1"+s;
			}
			else{
				s="2"+s;
			}
			dq/=3;
		}
		ll len=s.size();
		if(len<n){
			for(ll i = 1;i <= n-len;++i){
				s="0"+s;
			}
		}
		len=s.size();
		ll cl1=0,cl2=0,cl3=0;
		for(ll i = 0;i < len;++i){
			if(s[i]=='0'){
				cl1++;
			}
			else if(s[i]=='1'){
				cl2++;
			}
			else{
				cl3++;
			}
		}
		if(cl1>n/2||cl2>n/2||cl3>n/2){
			continue;
		}
		for(ll i = 0;i < len;++i){
			ls+=a[i+1][s[i]-'0'+1];
		}
	//	cout <<i<<" "<< s << " " << ls << endl;
		ans=max(ans,ls);
	}
	cout << ans << endl;
	return ;
}
void work3(){
	ll max1=0,max2=0;
	for(ll i = 1;i <= n;++i){
		if(a[i][1]>max1){
			max2=max1;
			max1=a[i][1];
		}
		else if(a[i][1]>max2){
			max2=a[i][1];
		}
	}
	cout << max1+max2 << endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		init();
		if(n<=10){
			work2();
		}
		else if(pd==1){
			work3();
		}
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

*/
