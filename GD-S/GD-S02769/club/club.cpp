#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 7;
const int inf = 1e18; 
int ans = 0;
struct Data{
	int x,y,z;
};
struct Point{
	int num,i,idx;
};
bool cmp(Point x,Point y){
	return x.num > y.num;
}
int n;
Data d[N];
vector<int> a,b,c;
vector<Point> ax,ay,bx,by,cx,cy;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		a.clear();
		b.clear();
		c.clear();
		ax.clear();
		bx.clear();
		cx.clear();
		ay.clear();
		by.clear();
		cy.clear(); 
		ans = 0;
		int ia = 0,ib = 0,ic = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> d[i].x >> d[i].y >> d[i].z;
		}
		int maxp = n / 2;
		for(int i = 1; i <= n; i++){
			if(d[i].x >= d[i].y and d[i].x >= d[i].z){
				a.push_back(i);
				ax.push_back({d[i].x - d[i].y,++ia,i});
				ay.push_back({d[i].x - d[i].z,ia,i});
			}
			else if(d[i].y >= d[i].x and d[i].y >= d[i].z){
				b.push_back(i);
				bx.push_back({d[i].y - d[i].x,++ib,i});
				by.push_back({d[i].y - d[i].z,ib,i});
			}
			else{
				c.push_back(i);
				cx.push_back({d[i].z - d[i].x,++ic,i});
				cy.push_back({d[i].z - d[i].y,ic,i});
			}
		}
		sort(ax.begin(),ax.end(),cmp);
		sort(ay.begin(),ay.end(),cmp);
		int sizea = a.size(),sizeb = b.size(),sizec = c.size();
		while(sizea > maxp){
			if(ax[ax.size() - 1].num < ay[ay.size() - 1].num and sizeb + 1 <= maxp){
				int i = ax[ax.size() - 1].idx;
				b.push_back(i);
				bx.push_back({d[i].y - d[i].x,i});
				by.push_back({d[i].y - d[i].z,i});	
				sizeb++;	
				a[ax[ax.size() - 1].i - 1] = 0;	
			}
			else{
				int i = ay[ay.size() - 1].idx;
				c.push_back(i);
				cx.push_back({d[i].z - d[i].x,i});
				cy.push_back({d[i].z - d[i].y,i});
				sizec++;	
				a[ay[ay.size() - 1].i - 1] = 0;		
			}
			sizea--;
			ax.pop_back();
			ay.pop_back();
		}
		sort(bx.begin(),bx.end(),cmp);
		sort(by.begin(),by.end(),cmp);
		while(sizeb > maxp){
			int minn = inf,mini;
			if(bx[bx.size() - 1].num < by[by.size() - 1].num and sizea + 1 <= maxp){
				int i = bx[bx.size() - 1].idx;
				a.push_back(i);
				ax.push_back({d[i].x - d[i].y,i});
				ay.push_back({d[i].x - d[i].z,i});		
				sizea++;
				b[bx[bx.size() - 1].i - 1] = 0;
			}
			else{
				int i = by[by.size() - 1].idx;
				c.push_back(i);
				cx.push_back({d[i].z - d[i].x,i});
				cy.push_back({d[i].z - d[i].y,i});		
				sizec++;	
				b[by[by.size() - 1].i - 1] = 0;
			}
			sizeb--;
			
			bx.pop_back();
			by.pop_back();
			
		}
		sort(cx.begin(),cx.end(),cmp);
		sort(cy.begin(),cy.end(),cmp);
		while(sizec > maxp){
			if(cx[cx.size() - 1].num < cy[cy.size() - 1].num and sizea + 1 <= maxp){
				int i = cx[cx.size() - 1].idx;
				a.push_back(i);
				ax.push_back({d[i].x - d[i].y,i});
				ay.push_back({d[i].x - d[i].z,i});		
				sizea++;	
				c[cx[cx.size() - 1].i - 1] = 0;
			}
			else{
				int i = cy[cy.size() - 1].idx;
				b.push_back(i);
				bx.push_back({d[i].y - d[i].x,i});
				by.push_back({d[i].y - d[i].z,i});		
				sizeb++;	
				c[cy[cy.size() - 1].i - 1] = 0;
			}
			sizec--;
			cx.pop_back();
			cy.pop_back();
		}
	
		for(int i = 0; i < a.size(); i++) ans += d[a[i]].x;
		for(int i = 0; i < b.size(); i++) ans += d[b[i]].y;
		for(int i = 0; i < c.size(); i++) ans += d[c[i]].z;
		cout << ans << "\n";
	}
} 
