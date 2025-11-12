#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
long long a[4],b[maxn][4],c[maxn],tot[maxn];
int t,n;
bool cmp(int x,int y){
	return x>y;
}
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long num[maxn]={0};
	cin>>t;
	for(int i = 1;i <= t;i++){
		int sum = 0;
		cin>>n;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= 3;k++){
				cin>>a[k];
				if(k>1&&a[k]!=0){
					sum = 1;
				}
			}
			
			sort(a+1,a+4,cmp);
			b[j][1] = a[1];
			b[j][2] = a[2];
			b[j][3] = a[3];
		}
		if(sum == 0){
			int m3 = 0;
			priority_queue<int>l;
			for(int p = 1;p <= n;p++){
				l.push(b[p][1]);
			}
			for(int p1 = 1;p1 <= n/2;p1++){
				m3+=l.top();
				l.pop();
			}
			num[i]=m3;
			continue;
		}
		if(n == 2){
			int m = 0;
			for(int x = 1; x <= 3;x++){
				for(int y = 1;y <= 3;y++){
					if(b[1][x]+b[2][y] >= m&&x != y){
						m = b[1][x] + b[2][y];
					}
				}
			}
			num[i] = m;
			continue;
		}
		
		if(n == 4){
			int m = 0;
			for(int x = 1; x <= 3;x++){
				for(int y = 1;y <= 3;y++){
					if(b[1][x]+b[2][y] > m&&x != y){
						m = b[1][x] + b[2][y];
					}
				}
			}
			int m1 = 0;
			for(int x1 = 1; x1 <= 3;x1++){
				for(int y1 = 1;y1 <= 3;y1++){
					if(b[3][x1]+b[4][y1] > m1&&x1 != y1){
						m1 = b[3][x1] + b[4][y1];
					}
				}
			}
			int m2=m1+m;
			num[i] = m2;
			continue;
			}
		}

	for(int i =1;i <= t;i++){
		cout<<num[i]<<endl;
	}
	return 0;
}
