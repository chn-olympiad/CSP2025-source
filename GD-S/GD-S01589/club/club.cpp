#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=1e5+10;
long long A[MAXN],B[MAXN],C[MAXN];
struct Node{
	int a[5];
	int fit,sce,trd;
}num[MAXN];
bool cmp (Node x,Node y){
	if (x.a[x.fit] == y.a[y.fit]){
		if (x.a[x.sce] == y.a[y.sce]){
			return x.a[x.trd] > y.a[y.trd];
		}else {
			return x.a[x.sce] > y.a[y.sce];
		}
	}else{
		return x.a[x.fit] > y.a[y.fit];
	}
}
void sp(int a,int b,int c,int i){
	if (a >= b){
		if (c >= a){
			num[i].fit=3;
			num[i].sce=1;
			num[i].trd=2;
		}else if(c >= b){
			num[i].fit=1;
			num[i].sce=3;
			num[i].trd=2;
		}else{
			num[i].fit=1;
			num[i].sce=2;
			num[i].trd=3;
		}
	}else {//b > a
		if (c >= b){
			num[i].fit=3;
			num[i].sce=2;
			num[i].trd=1;
		}else if(c >= a){
			num[i].fit=2;
			num[i].sce=3;
			num[i].trd=1;
		}else{
			num[i].fit=2;
			num[i].sce=1;
			num[i].trd=3;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		long long ans=0;
		int lena=0,lenb=0,lenc=0;
		int len=n/2;
		for (int i=1;i <= n;i++){
			scanf("%d %d %d",&num[i].a[1],&num[i].a[2],&num[i].a[3]);
			//if (!flag && num[i])
			sp(num[i].a[1],num[i].a[2],num[i].a[3],i);
		}
		sort(num+1,num+n+1,cmp);
		for (int i=1;i <= n;i++){
			if (num[i].fit == 1){
				if (lena < len){
					ans+=num[i].a[num[i].fit];
					lena++;
				}else if (num[i].sce==2){
					if (lenb < len){
						ans+=num[i].a[num[i].sce];
						lenb++;	
					}else if(lenc < len){
						ans+=num[i].a[num[i].trd];
						lenc++;
					}
				}else if (num[i].sce==3){
					if (lenc < len){
						ans+=num[i].a[num[i].sce];
						lenc++;	
					}else if(lenb < len){
						ans+=num[i].a[num[i].trd];
						lenb++;
					}
				}
			}else if (num[i].fit == 2){
				if (lenb < len){
					ans+=num[i].a[num[i].fit];
					lenb++;
				}else if (num[i].sce==1){
					if (lena < len){
						ans+=num[i].a[num[i].sce];
						lena++;	
					}else if(lenc < len){
						ans+=num[i].a[num[i].trd];
						lenc++;
					}
				}else if (num[i].sce==3){
					if (lenc < len){
						ans+=num[i].a[num[i].sce];
						lenc++;	
					}else if(lenb < len){
						ans+=num[i].a[num[i].trd];
						lenb++;
					}
				}
			}else if (num[i].fit == 3){
				if (lenc < len){
					ans+=num[i].a[num[i].fit];
					lenc++;
				}else if (num[i].sce==2){
					if (lenb < len){
						ans+=num[i].a[num[i].sce];
						lenb++;	
					}else if(lenc < len){
						ans+=num[i].a[num[i].trd];
						lenc++;
					}
				}else if (num[i].sce==1){
					if (lena < len){
						ans+=num[i].a[num[i].sce];
						lena++;	
					}else if(lenb < len){
						ans+=num[i].a[num[i].trd];
						lenb++;
					}
				}
			}
		}
		/*for (int i=1;i <= len;i++){
			ans+=num[i].a[num[i].fit];
		}*/
		cout << ans << "\n";
	}
	return 0;
} 
