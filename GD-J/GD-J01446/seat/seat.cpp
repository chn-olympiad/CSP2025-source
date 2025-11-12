#include <bits/stdc++.h>
using namespace std;
#define int long long
struct students{
	int score;
	int number;
}a[150];
bool cmp(students x,students y){
	return x.score>y.score;
}
int n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].number=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].number==1){
			int c,r;
			c=(i-1)/n+1;
			if(i%n==0){
				r=n;
			}else{
				r=i%n;
			}
			if(c%2==0){
				r=m+1-r;
			}
			cout<<c<<" "<<r;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
