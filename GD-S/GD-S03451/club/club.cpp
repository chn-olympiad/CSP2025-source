#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
typedef pair<int,int> pii;
int n;
int ans;
int lim;
struct node{
	int a,b,c;
}s[N];
priority_queue< pii,vector<pii>,greater<pii> >q1,q2,q3;
void work(){
	scanf("%d",&n);
	lim = n / 2;
	for(int i = 1;i <= n; i++){
		scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		int fa;
		if(q1.size() < lim)fa = s[i].a;
		else {
			pii t = q1.top();
			int p = t.second;
			fa = s[i].a + max(s[p].b,s[p].c)  - s[p].a;
		}
		int fb;
		if(q2.size() < lim)fb = s[i].b;
		else {
			pii t = q2.top();
			int p = t.second;
			fb = s[i].b + max(s[p].a,s[p].c)  - s[p].b;
		}
		int fc;
		if(q3.size() < lim)fc = s[i].c;
		else {
			pii t = q3.top();
			int p = t.second;
			fc = s[i].c + max(s[p].a,s[p].b)  - s[p].c;
		}
 		int maxnn = max(max(fa,fb),fc);
 		
// 		cout<<fa<<" "<<fb<<" "<<fc<<"\n\n";
 		
 		int space = 0;
 		if(fa == maxnn)space = max(space,lim - (int)q1.size());
 		if(fb == maxnn)space = max(space,lim - (int)q2.size());
 		if(fc == maxnn)space = max(space,lim - (int)q3.size());
 	
		if(fa == maxnn && lim - q1.size() == space){
			if(fa == maxnn && q1.size() < lim){
				q1.push({s[i].a - max(s[i].b,s[i].c),i});
				continue;
			}
			int p = q1.top().second;
			q1.pop();
			q1.push({s[i].a - max(s[i].b,s[i].c),i});
			if(s[p].b > s[p].c)q2.push({s[p].b - max(s[p].a,s[p].c),p});
			else q3.push({s[p].c - max(s[p].a,s[p].b),p});
			
		}
		if(fb == maxnn && lim - q2.size() == space){
			if(fb == maxnn && q2.size() < lim){
				q2.push({s[i].b - max(s[i].a,s[i].c),i});
				continue;
			}
			int p = q2.top().second;
			q2.pop();
			q2.push({s[i].b - max(s[i].a,s[i].c),i});
			if(s[p].a > s[p].c)q1.push({s[p].a - max(s[p].b,s[p].c),p});
			else q3.push({s[p].c - max(s[p].a,s[p].b),p});
		}
		if(fc == maxnn && lim - q3.size() == space){
			if(fc == maxnn && q3.size() < lim){
				q3.push({s[i].c - max(s[i].a,s[i].b),i});
				continue;
			}
			int p = q3.top().second;
			q3.pop();
			q3.push({s[i].c - max(s[i].a,s[i].b),i});
			if(s[p].a > s[p].b)q1.push({s[p].a - max(s[p].b,s[p].c),p});
			else q2.push({s[p].b - max(s[p].a,s[p].c),p});
		}
		
	}
	while(!q1.empty()){
//		cout << q1.top().second << "\n";
		ans += s[q1.top().second].a;
		q1.pop();
	}
//	cout<<"\n";
	while(!q2.empty()){
//		cout <<q2.top().second << "\n";
		ans += s[q2.top().second].b;
		q2.pop();
	}
//	cout<<"\n";
	while(!q3.empty()){
//		cout << q3.top().second << "\n";
		ans += s[q3.top().second].c;
		q3.pop();
	}
	printf("%d\n",ans);
	ans = 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work(); 
	return 0;
}  
/*
10
(3004 4255) 17336
(11894 5756) 17092
(8150) 14715 (10991)
(5149) 16652 (16780)
(11524) 11996 (5433)
(7690 10472) 19935
(1184 6516) 9246
(3231 5570) 10010
(8426) 16992 (4654)
18955 (13977 16657)

1
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657

1
4
100 99 10
100 10 10
99 0 0
101 0 0
*/
