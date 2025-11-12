#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll n,r,sumq1,sumq2,sumq3;
struct a{
	int x,y,z;
}b[N];
bool cmp(a w,a q){
	return w.x>q.x;
}
bool cmp1(a w,a q){
	return w.y>q.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>r;
		for(int i=0;i<r;i++){
			cin>>b[i].x>>b[i].y>>b[i].z;
		}
		sort(b,b+r,cmp);
		for(int i=0;i<r/2;i++){
			sumq1+=b[i].x;
			b[i].x=0,b[i].y=0;
			sort(b,b+r,cmp1);
			for(int j=0;j<r/2;j++){
				sumq1+=b[i].y;
			}
		}
		cout<<sumq1<<endl;
	}
	return 0;
} 
