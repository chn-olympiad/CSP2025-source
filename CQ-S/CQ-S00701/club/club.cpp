#include<bits/stdc++.h>
using namespace std;
long long T;
long long n,sum;
struct h{
	long long s1,s2,s3;
	long long t;
}o[100005];
long long v1,v2,v3;
bool cmp(h t1,h t2){
	return t1.t>t2.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		sum=0;
		cin>>n;
		v1=0,v2=0,v3=0;
		for(long long i=1;i<=n;i++){
			cin>>o[i].s1>>o[i].s2>>o[i].s3;
			long long mx=max(o[i].s1,max(o[i].s2,o[i].s3));
			long long mi=min(o[i].s1,min(o[i].s2,o[i].s3));
			o[i].t=mx-((o[i].s1+o[i].s2+o[i].s3)-mx-mi);
		}
		sort(o+1,o+n+1,cmp);
		for(long long i=1;i<=n;i++){
			long long mx=max(o[i].s1,max(o[i].s2,o[i].s3));
			long long mi=min(o[i].s1,min(o[i].s2,o[i].s3));
			long long mid=(o[i].s1+o[i].s2+o[i].s3)-mx-mi;
			if(mx==o[i].s1){
				if(v1<(n/2)){
					v1++;
					sum+=o[i].s1;
				}else if(mid==o[i].s2){
					v2++;
					sum+=o[i].s2;
				}else{
					v3++;
					sum+=o[i].s3;
				}
			}else if(mx==o[i].s2){
				if(v2<(n/2)){
					v2++;
					sum+=o[i].s2;
				}else if(mid==o[i].s1){
					v1++;
					sum+=o[i].s1;
				}else{
					v3++;
					sum+=o[i].s3;
				}
			}else{
				if(v3<(n/2)){
					v3++;
					sum+=o[i].s3;
				}else if(mid==o[i].s2){
					v2++;
					sum+=o[i].s2;
				}else{
					v1++;
					sum+=o[i].s1;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
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
*/
