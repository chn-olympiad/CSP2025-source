#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t;
long long m[N][4];
int a[N], b[N], c[N];
int ax[N], bx[N], cx[N];
int inline read(){
	int x=0, f=1;
	char ch = getchar();
	if(ch<'0' || ch>'9'){
		if(ch == '-'){
			f = -1;
			ch = getchar();
		}
	}
	if(ch>='0' && ch <='9'){
		x = x*10 + ch -'0';
		ch = getchar();
	}
	return x*f;
}
int main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	t = read();
	while(t--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		
		memset(ax, 0, sizeof(ax));
		memset(bx, 0, sizeof(bx));
		memset(cx, 0, sizeof(cx));
		
		int n;
		cin >> n;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++){
				m[i][j] = read();
			}
		}
		
		bool p1 = true;
		bool p2 = true;
		int tp[100005];
		for(int i=1; i<=n; i++){
			for(int j=2; j<=3; j++){
				if(m[i][j] != 0){
					p1 = false;
					break;
				}
			}
			tp[i] = m[i][1];
		}
		if(p1 == true){
			sort(tp, tp+n);
			int ans0 = 0;
			int x = n/2 + 1;
			if(n%2 == 1) x++;
			for(int i=n; i>=n-x; i--){
				ans0 += tp[i];
			}
			cout << ans0;
			continue;
		}
		int ans0 = 0;
		for(int i=1; i<=n; i++){
			if(m[i][3] != 0){
				p2 = false;
				break;
			}
			if(m[i][1] > m[i][2]){
				ans0 += m[i][1];
			}else{
				ans0 += m[i][2];
			}
		}
		if(p2 == true){
			cout << ans0;
			continue;
		}  
		if(n==2){
			int x1 = max(m[1][1], max(m[1][2], m[1][3]));
			int x2 = max(m[2][1], max(m[2][2], m[2][3]));
			if(x1 == m[1][1] && x2 == m[2][1]){
				int y2 = max(m[2][2], m[2][3]);
				int y1 = max(m[1][2], m[1][3]);
				ans0 = max(x1+y2, x2+y1);
			}
			if(x1 == m[1][2] && x2 == m[2][2]){
				int y2 = max(m[2][1], m[2][3]);
				int y1 = max(m[1][1], m[1][3]);
				ans0 = max(x1+y2, x2+y1);
			}
			if(x1 == m[1][3] && x2 == m[2][3]){
				int y2 = max(m[2][2], m[2][1]);
				int y1 = max(m[1][2], m[1][1]);
				ans0 = max(x1+y2, x2+y1);
			}	
			cout << ans0 << endl;
			continue;
		}
		int a1=0, b1=0, c1=0;	//人数
		int a2, am=N, a3;
		int b2, bm=N, b3;
		int c2, cm=N, c3;
		for(int i=1; i<=n; i++){
			if(m[i][1]>=m[i][2] && m[i][1]>=m[i][3]){
				if(am > a[a1]){
					am = a[a1];
					a2 = ax[a1];
				}		
				a[a1] = m[i][1];	//加入 
				ax[a1] = i;			//下标
				a1++;
				if(m[i][1] < am){
					a2 = i;		//标记min 
					am = m[i][1];
				}
				if(a1 > n/2){		//a换人 
					if(a[a2] < m[i][1]){	//换a2 
						if(m[a2][2] >= m[a2][3]){
							b[b1] = m[a2][2];
							bx[b1] = a2;
							b1++;
						}else{
							c[c1] = m[a2][3];
							cx[c1] = a2;
							c1++;
						}
						a[a2] = m[i][1];
						ax[a2] = i; 
					}else{
						if(m[i][2] >= m[i][3]){
							b[b1] = m[i][2];
							bx[b1] = i;
							b1++;
						}else{
							c[c1] = m[i][3];
							cx[c1] = i;
							c1++;
						}
					}
				}
				am = N;
				for(int j=1; j<=a1; i++){		//min
					if(a[j] < am){
						am = a[j];
						a2 = j;
					}
				}
			}
			
			else if(m[i][2]>m[i][1] && m[i][2]>=m[i][3]){
				if(bm > b[b1]){
					bm = b[b1];
					b2 = bx[b1];
				}
				b[b1] = m[i][2];
				bx[b1] = i;
				b1++;
				if(m[i][2] < bm){
					b2 = i;		//标记min 
					bm = m[i][1];
				}
				if(b1 > n/2){		//a换人 
					if(b[b2] < m[i][1]){	//换a2 
						if(m[b2][1] >= m[b2][3]){
							a[a1] = m[b2][1];
							ax[a1] = b2;
							a1++;
						}else{
							c[c1] = m[b2][3];
							cx[c1] = b2;
							c1++;
						}
						b[b2] = m[i][2];
						bx[b2] = i; 
					}else{
						if(m[i][1] >= m[i][3]){
							a[a1] = m[i][1];
							ax[a1] = i;
							a1++;
						}else{
							c[c1] = m[i][3];
							cx[c1] = i;
							c1++;
						}
					}
				}
				bm = N;
				for(int j=1; j<=b1; i++){
					if(b[j] < bm){
						bm = b[j];
						b2 = j;
					}
				}
			
			
			}else{
				if(cm > c[c1]){
					cm = c[c1];
					c2 = cx[c1];
				}
				c[c1] = m[i][3];
				cx[c1] = i;
				c1++;
				if(m[i][3] < cm){
					c2 = i;		//标记min 
					cm = m[i][3];
				}
				if(c1 > n/2){		//a换人 
					if(c[c2] < m[i][3]){	//换a2 
						if(m[c2][1] >= m[c2][2]){
							a[a1] = m[c2][1];
							ax[a1] = c2;
							a1++;
						}else{
							b[b1] = m[c2][2];
							bx[b1] = c2;
							b1++;
						}
						c[c2] = m[i][3];
						cx[c2] = i; 
					}else{
						if(m[i][1] >= m[i][2]){
							a[a1] = m[i][1];
							a1++;
						}else{
							b[b1] = m[i][2];
						}
					}
				}
				cm = N;
				for(int j=1; j<=b1; i++){
					if(c[j] < cm){
						cm = c[j];
						c2 = j;
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=1; i<=a1; i++)	ans += a[i];
		for(int i=1; i<=b1; i++)	ans += b[i];
		for(int i=1; i<=c1; i++)	ans += c[i];
		
		cout << ans << endl;	
	}
	
	
	return 0;
}
