#include<bits/stdc++.h>
using namespace std;
long long T,n,i,j,k,ans,n1,n2,n3,sum;
long long one[100005],two[100005],three[100005];
struct node{
	long long a;
	long long b;
	long long c;
	bool vis;
}s[100005];
bool cmp(node x,node y){
	if(x.a != y.a)return x.a > y.a;
	else{
		if(x.b != y.b)return x.b > y.b;
		else return x.c > y.c;
	}
}
bool cmp1(node x,node y){
	if(x.a != y.a)return x.a > y.a;
	else{
		if(x.c != y.c)return x.c > y.c;
		else return x.b > y.b;
	}
}
bool cmp2(node x,node y){
	if(x.b != y.b)return x.b > y.b;
	else{
		if(x.a != y.a)return x.a > y.a;
		else return x.c > y.c;
	}
}
bool cmp3(node x,node y){
	if(x.b != y.b)return x.b > y.b;
	else{
		if(x.c != y.c)return x.c > y.c;
		else return x.a > y.a;
	}
}
bool cmp4(node x,node y){
	if(x.c != y.c)return x.c > y.c;
	else{
		if(x.b != y.b)return x.b > y.b;
		else return x.a > y.a;
	}
}
bool cmp5(node x,node y){
	if(x.c != y.c)return x.a > y.a;
	else{
		if(x.a != y.a)return x.a > y.a;
		else return x.b > y.b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(i=1;i<=n;i++)cin>>s[i].a>>s[i].b>>s[i].c;
		sum = 0;
		sort(s+1,s+n+1,cmp);
		n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
		for(i=1;i<=n;i++){
			if(s[i].a>s[i].b&&s[i].a>s[i].c){
				if(n1 < n/2){
					ans += s[i].a;
					n1++;	
				}
				else{
					if(s[i].b > s[i].c){
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			if(s[i].b>s[i].a&&s[i].b>s[i].c){
				if(n2 < n/2){
					ans += s[i].b;
					n2++;	
				}
				else{
					if(s[i].a > s[i].c){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			sort(s+1,s+n+1,cmp1);
			n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
			for(i=1;i<=n;i++){
				if(s[i].a>s[i].b&&s[i].a>s[i].c){
					if(n1 < n/2){
						ans += s[i].a;
						n1++;	
					}
					else{
						if(s[i].b > s[i].c){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].b>s[i].a&&s[i].b>s[i].c){
					if(n2 < n/2){
						ans += s[i].b;
						n2++;	
					}
					else{
						if(s[i].a > s[i].c){
							if(n1 < n/2){
								ans += s[i].a;
								n1++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			sort(s+1,s+n+1,cmp2);
			n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
			for(i=1;i<=n;i++){
				if(s[i].a>s[i].b&&s[i].a>s[i].c){
					if(n1 < n/2){
						ans += s[i].a;
						n1++;	
					}	
					else{
						if(s[i].b > s[i].c){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].b>s[i].a&&s[i].b>s[i].c){
					if(n2 < n/2){
						ans += s[i].b;
						n2++;	
					}
					else{
						if(s[i].a > s[i].c){
							if(n1 < n/2){
								ans += s[i].a;
								n1++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			sort(s+1,s+n+1,cmp3);
			n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
			for(i=1;i<=n;i++){
				if(s[i].a>s[i].b&&s[i].a>s[i].c){
					if(n1 < n/2){
						ans += s[i].a;
						n1++;	
					}	
					else{
						if(s[i].b > s[i].c){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].b>s[i].a&&s[i].b>s[i].c){
					if(n2 < n/2){
						ans += s[i].b;
						n2++;	
					}
					else{
						if(s[i].a > s[i].c){
							if(n1 < n/2){
								ans += s[i].a;
								n1++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			sort(s+1,s+n+1,cmp4);
			n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
			for(i=1;i<=n;i++){
				if(s[i].a>s[i].b&&s[i].a>s[i].c){
					if(n1 < n/2){
						ans += s[i].a;
						n1++;	
					}	
					else{
						if(s[i].b > s[i].c){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].b>s[i].a&&s[i].b>s[i].c){
					if(n2 < n/2){
						ans += s[i].b;
						n2++;	
					}
					else{
						if(s[i].a > s[i].c){
							if(n1 < n/2){
								ans += s[i].a;
								n1++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			sort(s+1,s+n+1,cmp5);
			n1 = 0;  n2 = 0;  n3 = 0;  ans = 0;
			for(i=1;i<=n;i++){
				if(s[i].a>s[i].b&&s[i].a>s[i].c){
					if(n1 < n/2){
						ans += s[i].a;
						n1++;	
					}	
					else{
						if(s[i].b > s[i].c){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].b>s[i].a&&s[i].b>s[i].c){
					if(n2 < n/2){
						ans += s[i].b;
						n2++;	
					}
					else{
						if(s[i].a > s[i].c){
							if(n1 < n/2){
								ans += s[i].a;
								n1++;
							}
							else{
								ans += s[i].c;
								n3++;
							}
						}
					}
				}
				if(s[i].c>s[i].b&&s[i].c>s[i].a){
					if(n3 < n/2){
						ans += s[i].c;
						n3++;	
					}
					else{
						if(s[i].b > s[i].a){
							if(n2 < n/2){
								ans += s[i].b;
								n2++;
							}
							else{
								ans += s[i].a;
								n1++;
							}
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a>s[i].c){
					if(n1 < n2){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
				if(s[i].a==s[i].c&&s[i].a>s[i].b){
					if(n1 < n3){
						if(n1 < n/2){
							ans += s[i].a;
							n1++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
					else{
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].b;
							n2++;
						}
					}
				}
				if(s[i].b==s[i].c&&s[i].b>s[i].a){
					if(n3 < n2){
						if(n3 < n/2){
							ans += s[i].c;
							n3++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
					else{
						if(n2 < n/2){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].a;
							n1++;
						}
					}
				}
				if(s[i].a==s[i].b&&s[i].a==s[i].c){
					if(n1 < n2 && n1 < n3){
						ans += s[i].a;
						n1++;
					}
					else{
						if(n2 <= n1 && n2 <= n3){
							ans += s[i].b;
							n2++;
						}
						else{
							ans += s[i].c;
							n3++;
						}
					}
				}
			}
			sum = max(sum,ans);
			cout << sum << endl;
		}	
	return 0;
}
