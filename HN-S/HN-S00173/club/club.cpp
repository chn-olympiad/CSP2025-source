#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int aa,bb,cc;
};
node a[100005];
int xx[100005],yy[100005],zz[100005]; 
bool cmp(int x,int y){
	return x > y;
}
bool cmpa(node x,node y){
	return x.aa > y.aa;
}

bool cmp1(node x,node y){
	if(x.aa != y.aa) return x.aa > y.aa;
	if(x.bb != y.bb) return x.bb > y.bb;
	if(x.cc != y.cc) return x.cc > y.cc;
} //满足是那一排的最大，且排序靠前 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cout.tie(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int s1 = 0,s2 = 0,s3 = 0,h = n / 2;
		bool f1 = 1,f2 = 1;
		long long sum = 0;
		int l = 0,x = 0;
		for(int i = 1 ;i <= n;i++){
			cin >> a[i].aa >> a[i].bb >> a[i].cc;			
			if(a[i].bb != 0 or a[i].cc != 0) f1 = 0;
			if(a[i].cc != 0) f2 = 0;
			if(a[i].aa == 0 and a[i].bb == 0 or a[i].aa == 0 and a[i].cc == 0 or a[i].bb == 0 and a[i].cc == 0){
				x = i;
				l++;			
			}
		}
		if(n == 2 and l != 1){
			int max1 = max(a[1].aa,max(a[1].bb,a[1].cc));
			int max2 = max(a[2].aa,max(a[2].bb,a[2].cc));
			int q = 0,w = 0,sum = 0;
			if(a[1].aa == max1)q = 0;
			else if(a[1].bb == max1) q = 1;
			else q = 2;
			if(a[2].aa == max2)w = 0;
			else if(a[2].bb == max2) w = 1;
			else w = 2;			
			if(max1 > max2){
				sum += max1;
				if(q != w){
					sum += max2;
					cout << sum << '\n';
					continue;
				}
				if(q == 0 and w == 0){
					sum += max(a[2].bb,a[2].cc);
				}else if(q == 1 and w == 1){
					sum += max(a[2].aa,a[2].cc);
				}else if(q == 2 and w == 2){
					sum += max(a[3].bb,a[3].cc);
				}
			}
			else if(max1 < max2){
				sum += max1;
				if(q != w){
					sum += max2;
					cout << sum << '\n';
					continue;
				}
				if(q == 0 and w == 0){
					sum += max(a[1].bb,a[1].cc);
				}else if(q == 1 and w == 1){
					sum += max(a[1].aa,a[1].cc);
				}else if(q == 2 and w == 2){
					sum += max(a[1].bb,a[1].cc);
				}
			}else{
				sum += max1;
				if(q != w){
					sum += max2;
					cout << sum << '\n';
					continue;
				}
				if(q == 0 and w == 0){
					sum += max(max(a[2].bb,a[2].cc),max(a[1].bb,a[1].cc));
				}else if(q == 1 and w == 1){
					sum += max(max(a[2].aa,a[2].cc),max(a[1].aa,a[1].cc));
				}else if(q == 2 and w == 2){
					sum += max(max(a[2].bb,a[2].aa),max(a[1].bb,a[1].aa));

				}		
			}
			cout << sum << '\n';
			//continue;
		}
		else if(n == 2 and l == 1){
			
			if(a[x].aa != 0){
				sum += a[x].aa;
				x = abs(x - 1);
				sum += max(a[x].bb,a[x].cc);
				if(sum < a[x].aa) sum = a[x].aa;
			}
			else if(a[x].bb != 0){
				sum += a[x].bb;
				x = abs(x - 1);
				sum += max(a[x].aa,a[x].cc);
				if(sum < a[x].bb) sum = a[x].bb;
			}			
			else if(a[x].cc != 0){
				sum += a[x].cc;
				x = abs(x - 1);
				sum += max(a[x].bb,a[x].aa);
				if(sum < a[x].cc) sum = a[x].cc;
			}
			cout << sum << '\n';
			//continue;
		}
				
		else if(f1){
			sort(a + 1,a + n + 1,cmpa);
			for(int i = 1;i <= n / 2;i++) sum += a[i].aa;
			cout << sum << '\n';
			//continue;
		}
		else if(f2){
			for(int i = 1;i <= n;i++){
				if(a[i].aa > a[i].bb and s1 <= h){
					sum += a[i].aa;
					s1++;
				}else if(a[i].aa <= a[i].bb and s2 <= h){
					sum += a[i].bb;
					s2++;
				}
				else if(s2 > h and a[i].aa == a[i].bb){
					sum += a[i].bb;
					s1++;
				}
				
			}
			cout << sum << '\n';
			
		}
	
			
		else{
			memset(xx,0,sizeof xx);
			memset(yy,0,sizeof yy);
			memset(zz,0,sizeof zz);
			for(int i =1 ;i <= n;i++){
				int max1 = max(a[i].aa,max(a[i].bb,a[i].cc));
				if(max1 == a[i].aa){
					xx[i] = a[i].aa;
				}else if(max1 == a[i].bb){
					yy[i] = a[i].bb;
 				}else if(max1 == a[i].cc){
 					zz[i] = a[i].cc;
				}
			}
			sort(xx + 1,xx + n + 1,cmp);
			sort(yy + 1,yy + n + 1,cmp);
			sort(zz + 1,zz + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++) {
				sum = sum + xx[i]+yy[i]+zz[i];

			}
			cout << sum <<  '\n';
		}

		
	} 
	return 0;
}

