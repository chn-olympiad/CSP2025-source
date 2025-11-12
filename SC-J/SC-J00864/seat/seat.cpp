#include<bits/stdc++.h>
#define int long long
using namespace std;
int dir,n,m,cnt;
bool mp[15][15];
int dx[]={0,1,0,-1},dy[]={-1,0,1,0};
struct nodt{
	int cj;
	int id;
}st[110];
bool cmp(nodt a,nodt b){
	return a.cj>b.cj;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	 
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;cnt>=i;i++){
		cin>>st[i].cj;
		st[i].id=i;
	}
	sort(st+1,st+1+cnt,cmp);
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=1;n>=j;j++){
				//cout<<st[cnt].cj<<" ";
				if(st[cnt--].id==1){
					cout<<i<<" "<<j;
					break; 
				}
			}
		}
		else{
			for(int j=n;1<=j;j--){
				//cout<<st[cnt].cj<<" ";
				if(st[cnt--].id==1){
					cout<<i<<" "<<j;
					break; 
				}
			}
		}
	}		
	return 0; 
} 