#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int val,ID;
}stu[105];
int n,m,idx;
inline bool cmp(Stu a,Stu b){return a.val>b.val;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>stu[i].val,stu[i].ID=i;
	sort(stu+1,stu+1+(n*m),cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(stu[++idx].ID==1){
				if(i%2==1) cout<<i<<" "<<j;
				else cout<<i<<" "<<(n-j+1);
			}
		}
	}
	return 0;
}
