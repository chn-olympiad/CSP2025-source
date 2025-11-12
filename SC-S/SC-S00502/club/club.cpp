#include<bits/stdc++.h>
using namespace std;
int b[200005],c[200005],d[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1; i<=n; i++){
			int a1,a2,a3;
			int s1=0,s2=0,s3=0;
			cin>>a1>>a2>>a3;
			int cnt=max({a1,a2,a3});
			ans+=cnt;
			if(a1==cnt){
				b[i]=cnt;
				s1++;
			}else if(a2==cnt){
				c[i]=cnt;
				s2++;
			}else {
				d[i]=cnt;
				s3++;
			}
			if(s1>n/2){
				sort(b+1,b+1+s1);
				s1--;
				ans-=b[1];
				b[1]=1e9;
			}
			if(s2>n/2){
				sort(c+1,c+1+s2);
				s2--;
				ans-=c[1];
				c[1]=1e9;
			}
			if(s3>n/2){
				sort(d+1,d+1+s3);
				s3--;
				ans-=d[1];
				d[1]=1e9;
			}
		}
		cout<<ans<<'\n';
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