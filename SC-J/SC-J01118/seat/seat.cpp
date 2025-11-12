#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int pts;
	bool r;
}stu[110];
bool cmp(Stu a,Stu b){
	return a.pts>b.pts;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,now=0;
	cin>>n>>m;
	cin>>stu[1].pts;
	stu[1].r=1;
	for(int rp=2;rp<=n*m;rp++){
		cin>>stu[rp].pts;
		stu[rp].r=0;
	}sort(stu+1,stu+1+n*m,cmp);
	for(int rp=1;rp<=n;rp++){
		bool flag=0;
		if(rp%2==0){
			for(int wa=m;wa>=1;wa--){
				now++;
				if(stu[now].r==1){
					flag=1;
					cout<<rp<<' '<<wa;
					break;
				}
			}
		}else{
			for(int ac=1;ac<=m;ac++){
				now++;
				if(stu[now].r==1){
					flag=1;
					cout<<rp<<' '<<ac;
					break;
				}
			}
		}if(flag)break;
	}
	return 0;
}