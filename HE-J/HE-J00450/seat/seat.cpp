#include <bits/stdc++.h>
using namespace std;
int n,m,a,cnt,c,r;
struct St{
	int a,b,c;	//a原编号 b成绩 c成绩排序 
	bool operator < (const St &nd) const{
		return b < nd.b;		//成绩越高越靠前 
	} 
};
St seat[12][12];
bool isUpsidedown(int s){		//是否反着排 
	if(ceil(s/n%2)==0)		//是则反排 否则正排 
		return true;
	return false;
}
int ypos(int s){			//顺序为s的点的y坐标 
	int t=s%n;
	if(!t) t=s;
	if(!isUpsidedown(s))
		return t;
	else return n-s%n+1;
}
priority_queue<St> pq;
priority_queue<St> tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a;
		pq.push((St){i,a,0});
	}
	tmp = pq;
	cnt = 1;
	//清空pq 
	while(!pq.empty()) pq.pop();
	//按成绩编排顺序 St.c 
	while(!tmp.empty()){
		pq.push((St){tmp.top().a,tmp.top().b,cnt});
		cnt++;
		tmp.pop();
	}
	for(int i=1;i<=n*m;i++){
		if(!pq.empty()){
			int topc = pq.top().c;
			int tt = topc/2;
			if(topc%n>topc/2) tt+=1;
			seat[ypos(topc)][tt] = pq.top();
			if(seat[ypos(topc)][tt].a == 1){
				c = i;
				r = ypos(topc);
			}
			pq.pop();
		}
	}
	cout << c << ' ' << r;
	return 0;
}
