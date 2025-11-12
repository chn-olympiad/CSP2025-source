#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n,m;
int R,tot=1; 
int l,r;
array<int,101>score;

int main(int argc,char**argv) {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>R;
	score[1]=R;
	
	for(int i=2;i<=n*m;++i) cin>>score[i];
	
	sort(score.begin()+1,score.begin()+n*m+1,
		[](int _1,int _2){
			return _1>_2;
		});
		
	for(int i=1;i<=m;++i) {
		if(i&1)
			for(int j=1;j<=n;++j) {
				if(score[tot++]==R) {
					l=i;
					r=j;
					goto end;
				}			
			}
		else 
			for(int j=n;j>=1;--j) {
				if(score[tot++]==R) {
					l=i;
					r=j;
					goto end;
				}	
			}
	}
	
	end:
		cout<<l<<' '<<r;
	
	return 0;
}
