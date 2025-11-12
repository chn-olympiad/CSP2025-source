#include<bits/stdc++.h>
using namespace std;
struct s{
	int idx,score;
}a[110];
int n,m;
bool cmp(s a,s b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].idx=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].idx==1){
			int x=(i+n-1)/n,y=i-(x-1)*n;
			cout<<x<<" "<<y;
			return 0;
		}
	}
}