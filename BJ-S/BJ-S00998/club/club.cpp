#include "bits/stdc++.h"
using namespace std;

struct person {
	int a,b,c;	
	int one,two,three;
	int rone,rtwo,rthree;
	void exec() {
		rone = max(a,max(b,c));
		rthree = min(a,min(b,c));
		if(rone == a) {
			one = 1;
		}
		if(rone == b) {
			one = 2;
		}
		if(rone == c) {
			one = 3;
		}
		
		if(rthree == a) {
			three = 1;
		}
		if(rthree == b) {
			three = 2;
		}
		if(rthree == c) {
			three = 3;
		}
		
		if(a != one && a != three) {
			two = 1;
			rtwo = a;
		}
		if(b != one && b != three) {
			two = 2;
			rtwo = b;
		}
		else {
			two = 3;
			rtwo = c;
		}
		
	}
	
}a[100005];


bool cmp(person x,person y) {
	if(x.rone == y.rone) {
		if(x.rtwo == y.rtwo) {
			return x.rthree > y.rthree;
		}
		else return x.rtwo > y.rtwo && x.rtwo + y.rthree > x.rthree + y.rtwo;
	}
	else return (x.rone > y.rone && (x.rone + y.rtwo > y.rone + x.rtwo && x.rone + y.rthree > y.rone + x.rthree));
}

bool cmpv2(person x,person y) {
	if(x.rone == y.rone) {
		if(x.rtwo == y.rtwo) {
			return x.rthree > y.rthree;
		}
		else return x.rtwo > y.rtwo ;
	}
	else return (x.rone > y.rone );
}

void mysort(person a[],int n) {
	
	for(int i = 1;i <= n;i++) {
		for(int j = n-1;j >= i;j--) {
			if(cmp(a[j],a[j+1])) {
				swap(a[j],a[j+1]);
			}
		}
	}
	
}

int main() {
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	
	//fang bao 0 zhuangzhi
	
	
	while(T--) {
		int res = 0;

		int n;
		cin>>n;
		int t[] = {0,n / 2,n / 2,n / 2};
		for(int i = 1;i <= n;i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].exec();
		}
		
		if(n == 2) {
			
			
			//fang bao 0 zhuang zhi
			int ab = a[1].rone + a[2].rtwo;
			int ac = a[1].rone + a[2].rthree;
			int bc = a[1].rtwo + a[2].rthree;
			int ba = a[1].rtwo + a[2].rone;
			int ca = a[1].rthree + a[2].rone;
			int cb = a[1].rthree + a[2].rtwo;
			
			cout<<max(ab,max(ac,max(bc,max(ba,max(ca,cb)))))<<endl;
			
			continue;
		}
		
		sort(a+1,a+n+1,cmp);	
		//sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n - 1;i++) {
			
			//cout<<"debug:"<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
			
			if(t[a[i].one]){
				res += a[i].rone;
				t[a[i].one]--;
			}
			else if(t[a[i].two]) {
				res += a[i].rtwo;
				t[a[i].two]--;

			}
			else if(t[a[i].three]) {
				res += a[i].rthree;
				t[a[i].three]--;

			}
			
		}
			
		cout<<res<<endl;
			
		
		
		
	}
	
	return 0;
}



/*
 ni tian zhe yi kuai
 
  
  
  
  
  
  
  
  
#include "bits/stdc++.h"
using namespace std;

int n;
int v[10005],v2[10005],v3[10005];
int w,w2,w3;
int dp[205][205][205];

int main() {
	
	int T;
	cin>>T;
	while(T--) {
		
			
		cin>>n;
		for(int i = 1;i <= n;i++) {
			int a,b,c;
			cin>>a>>b>>c;
			
			v[i] = a;
			v2[i] = b;
			v3[i] = c;
			
		}
		w = n / 2;
		w2 = n / 2;
		w3 = n / 2;
		
		for(int i = 1;i <= n;i++) {
			for(int j = w;j >= v[i];j--) {
				for(int k = w2;k >= v2[i];k--) {
					for(int x = w3;x >= v3[i];x--) {
						dp[j][k][x] = max(dp[j][k][x],max(dp[j-1][k][x] + v[i],max(dp[j][k-1][x] + v2[i],dp[j][k][x-1] + v3[i])));
					}
				}
			}
		}
	}
	
	int res = -1;
	for(int i = 1;i <= 200;i++) {
		for(int j = 1;j <= 200;j++) {
			for(int k = 1;k <= 200;k++) {
				res = max(res,dp[i][j][k]);
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}
*/
