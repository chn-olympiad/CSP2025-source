#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+67;
int t;
int n;
struct nod{
	int a1,a2,a3;
	int u1,u2,u3;
}aa[maxn];
bool cmp(nod x,nod y){
	if(x.a1 == y.a1){
		if(x.a2 == y.a2){
			return x.a3 > y.a3;
		}
		else return x.a2 > y.a2;
	}
	else return x.a1 > y.a1;
}
ll anser;
bool flag = 0;
void dfs(int depth,ll answer,int c1,int c2,int c3,int an){
	if(flag == 1) return;//jian_zhi
	if(depth >= an){
		if(answer > anser){
			anser = answer;
//			printf("%d %d\n",depth,answer);
		}
//		else{
//			flag = 1;
//		}
		return;
	}
//	printf("%d %d %d %d %d\n",depth,answer,c1,c2,c3);
	if(flag == 1) return;
	if(c1 < an/2){
		dfs(depth+1,answer+aa[depth+1].a1,c1+1,c2,c3,an);
	}
	if(flag == 1) return;
	if(c2 < an/2){
		dfs(depth+1,answer+aa[depth+1].a2,c1,c2+1,c3,an);
	}
	if(flag == 1) return;
	if(c3 < an/2){
		dfs(depth+1,answer+aa[depth+1].a3,c1,c2,c3+1,an);
	}
	if(flag == 1) return;
	return;
}
int main(){
//	printf("1\n");
//	printf("2\n");
//	printf("3\n");
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ll cnt1 = 0,cnt2 = 0,cnt3 = 0;// cnt = 0,else WA
		ll ans = 0;//ans = 0,else WA
		scanf("%d",&n);
		for(int i = 1;i <= n; i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			aa[i].a1 = a;
			aa[i].a2 = b;
			aa[i].a3 = c;
			aa[i].u1 = 1;
			aa[i].u2 = 2;
			aa[i].u3 = 3;
//			if(aa[i].a1 < aa[i].a2){
//				swap(aa[i].a1,aa[i].a2);
//				swap(aa[i].u1,aa[i].u2);
//			}
//			if(aa[i].a2 < aa[i].a3){
//				swap(aa[i].a2,aa[i].a3);
//				swap(aa[i].u2,aa[i].u3);
//			}
//			if(aa[i].a1 < aa[i].a3){
//				swap(aa[i].a1,aa[i].a3);
//				swap(aa[i].u1,aa[i].u3);
//			}
//			if(aa[i].a1 < aa[i].a2){
//				swap(aa[i].a1,aa[i].a2);
//				swap(aa[i].u1,aa[i].u2);
//			}
//			if(aa[i].a2 < aa[i].a3){
//				swap(aa[i].a2,aa[i].a3);
//				swap(aa[i].u2,aa[i].u3);
//			}
//			if(aa[i].a1 < aa[i].a3){
//				swap(aa[i].a1,aa[i].a3);
//				swap(aa[i].u1,aa[i].u3);
//			}
			//at now x.a1 >= x.a2 >= x.a3
		}
//		sort(aa+1,aa+1+n,cmp);
//		
//		printf("\n");
//		for(int i = 1;i <= n; i++){
//			printf("%d %d %d\n",aa[i].a1,aa[i].a2,aa[i].a3);
//			printf("%d %d %d\n\n",aa[i].u1,aa[i].u2,aa[i].u3);
//		}
//		
//		
//		printf("\n\n");
		
		anser = 0;
		flag = 0;
		dfs(0,0,0,0,0,n);
		printf("%lld\n",anser);
		
//		for(int i = 1;i <= n ;i++){
//			if(aa[i].u1 == 1){
//				if(cnt1 < n/2){
//					++cnt1;
//					ans += aa[i].a1;
////					printf("1\n");
//				}
//				else{
//					if(aa[i].u2 == 2){
//						if(cnt2 < n/2){
//							++cnt2;
//							ans += aa[i].a2;
////							printf("2\n");
//						}
//						else{
//							++cnt3;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//					if(aa[i].u2 == 3){
//						if(cnt3 < n/2){
//							++cnt3;
//							ans += aa[i].a3;
////							printf("2\n");
//						}
//						else{
//							++cnt2;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//				}
//			}
//			if(aa[i].u1 == 2){
//				if(cnt2 < n/2){
//					++cnt2;
//					ans += aa[i].a1;
////					printf("1\n");
//				}
//				else{
//					if(aa[i].u2 == 1){
//						if(cnt1 < n/2){
//							++cnt1;
//							ans += aa[i].a2;
////							printf("2\n");
//						}
//						else{
//							++cnt3;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//					if(aa[i].u2 == 3){
//						if(cnt3 < n/2){
//							++cnt3;
//							ans += aa[i].a2;
////							printf("2\n");
//						}
//						else{
//							++cnt1;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//				}
//			}
//			if(aa[i].u1 == 3){
//				if(cnt3 < n/2){
//					++cnt3;
//					ans += aa[i].a1;
////					printf("1\n");
//				}
//				else{
//					if(aa[i].u2 == 1){
//						if(cnt1 < n/2){
//							++cnt1;
//							ans += aa[i].a2;
////							printf("2\n");
//						}
//						else{
//							++cnt2;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//					if(aa[i].u2 == 2){
//						if(cnt2 < n/2){
//							++cnt2;
//							ans += aa[i].a2;
////							printf("2\n");
//						}
//						else{
//							++cnt1;
//							ans += aa[i].a3;
////							printf("3\n");
//						}
//					}
//				}
//			}
//		}
//		printf("%lld\n",ans);
	}
	/*
	
	think about dp
	this problem a little like kkksc03 before exam
	in dp:
		n = n;
		sum = n/2;
		but,this problem is not that
		in the kksc03 , we have 2 bags
		but now we have 3 bags
		and other,ans is the everyone well number's sum
		the kkk is the better bags top number
		
	others :
		we think about tan_xin
		we need to solve the everyone's well number's sum
		at the first:
			we think about the max of ai1 ~ ai3
			but we have a question,every club popular must not more than n/2
		at the second:
			we sort the a
			the sort rules:
				1.x.a1 > x. a2 > x.a3
				2.x.a1 > y.a1
					else x.a2 > y.a2
						else x.a3 > y.a3
			if this student very want to this club(ai1 is this club max or more than n/2 students)
			this student to this club
		at now we know some answer
		but ,the tan_xin has some wrong:
			such as this:
				2
				10 9 0
				4 0 0
			in tan_xin,the answer is 10 + 0 = 10
			but the true answer is 9 + 4 = 13
	
	and we have third solves:
		Because of the n <= 10^5
		and only 3 clubs
		so ,we can to every number to run
		This solves is dfs
	*/
	
	return 0;
}
