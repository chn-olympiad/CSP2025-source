#include<bits/stdc++.h>
using namespace std;

struct point{
	int newn;
	int k;
	int a;
	int b;
	int c;
};
queue<point> q;

const int SIZE = 100005;
int sz[3][SIZE] = {0};

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t --){
		int n;
		cin>> n;
		
		for(int i = 0; i < n; i ++){
			cin >> sz[0][i] >> sz[1][i] >> sz[2][i];
		}
		
		int res = 0;
		
		for(int i = 0; i < 3; i ++){
			point p;
			p.k = 0;
			p.newn = sz[i][0];
			p.a = 0;
			p.b = 0;
			p.c = 0;
			
			if(i == 0) p.a++;
			else if(i == 1) p.b ++;
			else p.c ++;
			
			q.push(p);
		}
		
		while(!q.empty()){
			point np;
			np.a = q.front().a;
			np.b = q.front().b;
			np.c = q.front().c;
			np.k = q.front().k;
			np.newn = q.front().newn;
			
			q.pop();
			
			if(np.k == n - 1) {
				if(np.newn > res) res = np.newn;
			}
			
			else{
				for(int i = 0; i < 3; i ++){
					point nnp;
					nnp.a = np.a;
					nnp.b = np.b;
					nnp.c = np.c;
					nnp.k = np.k + 1;
					nnp.newn = np.newn;
					
					if(i == 0 && nnp.a + 1 <= n / 2){
						nnp.a ++;
						nnp.newn += sz[i][nnp.k];
						q.push(nnp);
					}
					if(i == 1 && nnp.b + 1 <= n / 2){
						nnp.b ++;
						nnp.newn += sz[i][nnp.k];
						q.push(nnp);
					}
				    if(i == 2 && nnp.c + 1 <= n / 2){
						nnp.c ++;
						nnp.newn += sz[i][nnp.k];
						q.push(nnp);
					}
				}
			}
		}
		cout << res << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
