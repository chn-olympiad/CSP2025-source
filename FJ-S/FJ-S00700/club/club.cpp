#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],cnt[3];

struct node{
	int maxi,maxn,s;
}m[100001],v[100001];

bool cmp(node x,node y){
	return x.s>y.s;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0;i<3;i++) cnt[i] = 0;
		for(int i = 0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int man,mai,sei,sen;
			
			if(a[i][0] > a[i][1]){
				if(a[i][0] > a[i][2]){
					man = a[i][0],mai = 0;
					if(a[i][1] > a[i][2]) sen = a[i][1],sei = 1;
					else sen = a[i][2],sei = 2;
				}else{
					man = a[i][2],mai = 2;
					sen = a[i][0],sei = 0;
				}
			}else{
				if(a[i][1] > a[i][2]){
					man = a[i][1],mai = 1;
					if(a[i][0] > a[i][2]) sen = a[i][0],sei = 0;
					else sen = a[i][2],sei = 2;
				}else{
					man = a[i][2],mai = 2;
					sen = a[i][1],sei = 1;
				}
			}
	    	
			m[i].s = man-sen;
			m[i].maxn = man;
			cnt[mai]++;
			m[i].maxi = mai;
		}
	
		int ans = 0;
		int ma = 0;
		for(int i = 1;i<=2;i++){
			if(cnt[ma] < cnt[i]) ma = i;
		}
	
		int l = 0;
		for(int i = 0;i<n;i++){
			if(m[i].maxi != ma) ans+=a[i][m[i].maxi];
			else v[l] = m[i],l++;
		}
		
//		for(int i = 0;i<l;i++){
//			cout<<v[i].maxi<<" "<<v[i].maxn<<" "<<v[i].s<<endl;
//		}
		
		sort(v,v+l,cmp);
//		
//		for(int i = 0;i<l;i++){
//			cout<<v[i].maxi<<" "<<v[i].maxn<<" "<<v[i].s<<endl;
//		}
//		
		int i = 0;
		for(;i<l&&i<n/2;i++){
			ans+=v[i].maxn;
		}

		for(;i<l;i++){
			ans+=v[i].maxn-v[i].s;
			//cout<<v[i].maxn-v[i].s<<endl;
		}
		
		cout<<ans<<'\n';
	}

	cout<<endl;
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
