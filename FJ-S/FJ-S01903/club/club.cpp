#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
struct person{
	int val[4],b[4],fir,sec;
}a[500001];
int ans = 0;
priority_queue<int,vector<int>,greater<int> >q[4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		ans = 0;
		for(int i = 1;i<=n;i++){
			int mapos = 0,ma2 = 0;
			a[i].val[0] = -2e18;
			for(int j = 1;j<=3;j++){
				scanf("%lld",&a[i].val[j]);
				if(a[i].val[j]>a[i].val[mapos])ma2 = mapos,mapos = j;
				else if(a[i].val[j]>a[i].val[ma2])ma2 = j;
				a[i].b[j] = a[i].val[j];
			}
			a[i].fir = mapos;
			a[i].sec = ma2;
//			sort(a[i].b+1,a[i].b+4);
//			for(int j = 1;j<=3;j++){
//				cout<<a[i].b[j]<<" ";
//			}
//			cout<<endl;
		}
		for(int i = 1;i<=n;i++){
//			cout<<a[i].fir<<" "<<a[i].sec<<endl;
			if((int)(q[a[i].fir].size())>=n/2){
//				cout<<"!"<<endl;
				int ld = a[i].val[a[i].fir]-a[i].val[a[i].sec];
//				cout<<"comp:"<<ld<<" "<<q[a[i].fir].top()<<endl;
				if(ld>q[a[i].fir].top()){
//					cout<<"on"<<endl;
					ans-=q[a[i].fir].top();
					q[a[i].fir].pop();
					q[a[i].fir].push(ld);
					ans+=a[i].val[a[i].fir];
				}else{
//					cout<<"off"<<endl;
					ans+=a[i].val[a[i].sec];
				}
			}else{
				int ld = a[i].val[a[i].fir]-a[i].val[a[i].sec];
				ans+=a[i].val[a[i].fir];
				q[a[i].fir].push(ld);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
n/2?nabushisongde
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
jideqingkong
*/
