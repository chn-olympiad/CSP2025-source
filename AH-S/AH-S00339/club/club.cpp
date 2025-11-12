 #include <bits/stdc++.h>
#define debug(x) printf("In Function %s,Line %d,%s:%d.\n",__FUNCTION__,__LINE__,#x,x)
#define cputime printf("CPU used time:%.3lf.\n",(double) clock() / CLOCKS_PER_SEC)
#define upp(a,b,c) for(a=(b);a<=(c);a++)
#define low(a,b,c) for(a=(b);a>=(c);a++)
using namespace std;
typedef int var;

template <typename T> inline void read(T &x){
	static char ch;
	static int y;
	x = 0;
	y = 1;
	ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			y = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	x *= y;
}

const int N=1e5+5,M=5;
var T,n,a[N][M],num[M],k,ans,maxn,maxc,wh,ct;

void code(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	var i,j;
    read(T);
    while(T--){
    	// many as clear
    	priority_queue<var,vector<var>,greater<var> > q[M];
    	fill(num+1,num+4,0);
    	ans = 0;
    	read(n);
        upp(i,1,n){
        	maxn = maxc = 0;
        	upp(j,1,3){
        		read(a[i][j]);
        		if(maxn < a[i][j]){
        			maxc = maxn;
        			maxn = a[i][j];
        			wh = j;
        		}
        		else if(maxc < a[i][j]){
        			maxc = a[i][j];
        		}
        	}
        	q[wh].push(maxn - maxc);
        	ans += maxn;
        	num[wh]++;
        }
        upp(i,1,3){
        	if(num[i] > (n>>1)){
        		k = num[i] - (n>>1);
        		ct = i;
        		break;
        	}
        }
        upp(i,1,k){
        	ans -= q[ct].top();
        	q[ct].pop();
        }
        printf("%d\n",ans);
    }
}
int main(){
	code();
	return 0;
}