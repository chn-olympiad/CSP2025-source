#include<bits/stdc++.h>
#define int long long 
#define fast int 

using namespace std;

const int N=1e5+100;

int n,m,l=1;

int cnt=0;

struct node{
	int val,id;
}a[N];

bool cmp(node a,node b){
	return a.val>b.val;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for (fast i=1;i<=n*m;i++) {cin>>a[i].val;a[1].id=1;}
	
	sort(a+1,a+n*m+1,cmp);
	
	for (fast i=1;i<=n*m;i++){
		if (a[i].id==1){
			cnt=i;
			if (l%2==0){
				cout<<ceil(cnt*1.0/n)<<" "<<n-(cnt%n)+1;
				return 0;
			}
			else{
				if (cnt%n==0){
					cout<<ceil(cnt*1.0/n)<<" "<<n;
					return 0;
				}
				cout<<ceil(cnt*1.0/n)<<" "<<cnt%n;
				return 0;
			}
		}
		if (i%n==0) l++;
	}
	
	return 0;
}
/*

3 3
94 95 96 97 98 99 100 93 92

2 2
98 99 100 97

2 2
99 100 97 98

2 3
98 100 99 97 96 95

luogu UID: 1072112 and 1371852
SC的好花花

认识的人好多  我不想退役

不 我不想

*/