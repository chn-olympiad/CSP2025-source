#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll Misaka=998244353;
int n,m;
pair<int,int> c[507];
bool s[507];

int main(){
	freopen("employ.in" ,"r",stdin );
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char h; cin>>h;
		s[i]=h-'0';
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i].second),c[i].first=i;
	
	if(n<=10){
		int u=0;
		sort(c+1,c+n+1);
		do{
			int t=0,r=0;
			for(int i=1;i<=n;i++){
				if(t>=c[i].second||s[i]==false) t++;
				else r++;
			}
			if(r>=m) u++;
		}while(next_permutation(c+1,c+n+1));
		printf("%d",u);
	}
	
	
	
	return 0;
}

