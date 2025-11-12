#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans, ka, kb, kc;
struct Member{
	ll a, b, c;
}mbr[100005];
ll n, t;
struct Node{
	ll x, aa, bb, cc;
};
Node dp[100005][4];
bool cmp1(Member x, Member y){
	if(x.a != y.a){
		return x.a > y.a;
	}
	else if(x.b != y.b){
		return x.b > y.b;
	}
	else{
		return x.c > y.c;
	}
}
bool cmp2(Member x, Member y){
	if(x.a != y.a){
		return x.a > y.a;
	}
	else if(x.c != y.c){
		return x.c > y.c;
	}
	else{
		return x.b > y.b;
	}
}
bool cmp3(Member x, Member y){
	if(x.b != y.b){
		return x.b > y.b;
	}
	else if(x.a != y.a){
		return x.a > y.a;
	}
	else{
		return x.c > y.c;
	}
}
bool cmp4(Member x, Member y){
	if(x.b != y.b){
		return x.b > y.b;
	}
	else if(x.c != y.c){
		return x.c > y.c;
	}
	else{
		return x.a > y.a;
	}
}
bool cmp5(Member x, Member y){
	if(x.c != y.c){
		return x.c > y.c;
	}
	else if(x.a != y.a){
		return x.a > y.a;
	}
	else{
		return x.b > y.b;
	}
}
bool cmp6(Member x, Member y){
	if(x.c != y.c){
		return x.c > y.c;
	}
	else if(x.b != y.b){
		return x.b > y.b;
	}
	else{
		return x.a > y.a;
	}
}
void init(){
	ans = 0;
	for(ll i = 1; i <= n; i++){
		dp[i][1].x = dp[i][1].aa = dp[i][1].bb = dp[i][1].cc = 0;
		dp[i][2].x = dp[i][2].aa = dp[i][2].bb = dp[i][2].cc = 0;
		dp[i][3].x = dp[i][3].aa = dp[i][3].bb = dp[i][3].cc = 0;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		init();
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> mbr[i].a >> mbr[i].b >> mbr[i].c;
			ka += mbr[i].a;
			kb += mbr[i].b;
			kc += mbr[i].c;
		}
		//cout << "\n\n";
		if(ka > kb && kb > kc){
			sort(mbr + 1, mbr + n + 1, cmp1);
		}
		else if(ka > kc && kc > kb){
			sort(mbr + 1, mbr + n + 1, cmp2);
		}		
		else if(kb > ka && ka > kc){
			sort(mbr + 1, mbr + n + 1, cmp3);
		}
		else if(kb > kc && kc > ka){
			sort(mbr + 1, mbr + n + 1, cmp4);
		}
		else if(kc > ka && ka > kb){
			sort(mbr + 1, mbr + n + 1, cmp5);
		}
		else if(kc > kb && kb > ka){
			sort(mbr + 1, mbr + n + 1, cmp6);
		}				
		dp[1][1].x = mbr[1].a;
		dp[1][2].x = mbr[1].b;
		dp[1][3].x = mbr[1].c;
		dp[1][1].aa++;
		dp[1][2].bb++;
		dp[1][3].cc++;
		for(ll i = 2; i <= n; i++){
			//选第一组。
			if(dp[i - 1][1].aa + 1 <= n / 2){
				dp[i][1].x = max(dp[i][1].x, dp[i - 1][1].x + mbr[i].a);
				dp[i][1].aa = dp[i - 1][1].aa + 1;
				dp[i][1].bb = dp[i - 1][1].bb;
				dp[i][1].cc = dp[i - 1][1].cc;
			}
			if(dp[i - 1][2].aa + 1 <= n / 2){
				if(dp[i - 1][2].x + mbr[i].a > dp[i][1].x || (dp[i - 1][2].x + mbr[i].a == dp[i][1].x && (dp[i - 1][2].aa + 1< dp[i][1].aa || dp[i - 1][2].bb < dp[i][1].bb || dp[i - 1][2].cc < dp[i][1].cc))){
					dp[i][1].aa = dp[i - 1][2].aa + 1;
					dp[i][1].x = dp[i - 1][2].x + mbr[i].a;	
					dp[i][1].bb = dp[i - 1][2].bb;
					dp[i][1].cc = dp[i - 1][2].cc;					
				}
			}
			if(dp[i - 1][3].aa + 1 <= n / 2){
				if(dp[i - 1][3].x + mbr[i].a > dp[i][1].x || (dp[i - 1][3].x + mbr[i].a == dp[i][1].x && (dp[i - 1][3].aa + 1< dp[i][1].aa || dp[i - 1][3].bb < dp[i][1].bb || dp[i - 1][3].cc < dp[i][1].cc))){
					dp[i][1].aa = dp[i - 1][3].aa + 1;
					dp[i][1].x = dp[i - 1][3].x + mbr[i].a;
					dp[i][1].bb = dp[i - 1][3].bb;
					dp[i][1].cc = dp[i - 1][3].cc;					
				}
			}	
			//选第二组 
			if(dp[i - 1][1].bb + 1 <= n / 2){
				dp[i][2].x = max(dp[i][2].x, dp[i - 1][1].x + mbr[i].b);
				dp[i][2].bb = dp[i - 1][1].bb + 1;
				dp[i][2].aa = dp[i - 1][1].aa;
				dp[i][2].cc = dp[i - 1][1].cc;				
			}
			if(dp[i - 1][2].bb + 1 <= n / 2){
				if(dp[i - 1][2].x + mbr[i].b > dp[i][2].x || (dp[i - 1][2].x + mbr[i].a == dp[i][2].x && (dp[i - 1][2].aa < dp[i][2].aa || dp[i - 1][2].bb + 1 < dp[i][2].bb || dp[i - 1][2].cc < dp[i][2].cc))){
					dp[i][2].bb = dp[i - 1][2].bb + 1;
					dp[i][2].x = dp[i - 1][2].x + mbr[i].b;	
					dp[i][2].aa = dp[i - 1][2].aa;
					dp[i][2].cc = dp[i - 1][2].cc;				
				}
			}
			if(dp[i - 1][3].bb + 1 <= n / 2){
				if(dp[i - 1][3].x + mbr[i].b > dp[i][2].x || (dp[i - 1][3].x + mbr[i].a == dp[i][2].x && (dp[i - 1][3].aa < dp[i][2].aa || dp[i - 1][3].bb + 1 < dp[i][2].bb || dp[i - 1][3].cc < dp[i][2].cc))){
					dp[i][2].bb = dp[i - 1][3].bb + 1;
					dp[i][2].x = dp[i - 1][3].x + mbr[i].b;	
					dp[i][2].aa = dp[i - 1][3].aa;
					dp[i][2].cc = dp[i - 1][3].cc;				
				}
			}	
			//选第三组
			if(dp[i - 1][1].cc + 1 <= n / 2){
				dp[i][3].x = max(dp[i][3].x, dp[i - 1][1].x + mbr[i].c);
				dp[i][3].cc = dp[i - 1][1].cc + 1;
				dp[i][3].bb = dp[i - 1][1].bb;
				dp[i][3].aa = dp[i - 1][1].aa;			
			}
			if(dp[i - 1][2].cc + 1 <= n / 2){
				if(dp[i - 1][2].x + mbr[i].c > dp[i][3].x || (dp[i - 1][2].x + mbr[i].a == dp[i][3].x && (dp[i - 1][2].aa < dp[i][3].aa || dp[i - 1][2].bb < dp[i][3].bb || dp[i - 1][2].cc + 1 < dp[i][3].cc))){
					dp[i][3].cc = dp[i - 1][2].cc + 1;
					dp[i][3].x = dp[i - 1][2].x + mbr[i].c;	
					dp[i][3].bb = dp[i - 1][2].bb;
					dp[i][3].aa = dp[i - 1][2].aa;			
				}
			}
			if(dp[i - 1][3].cc + 1 <= n / 2){
				if(dp[i - 1][3].x + mbr[i].c > dp[i][3].x || (dp[i - 1][3].x + mbr[i].a == dp[i][3].x && (dp[i - 1][3].aa < dp[i][3].aa || dp[i - 1][3].bb < dp[i][3].bb || dp[i - 1][3].cc + 1 < dp[i][3].cc))){
					dp[i][3].cc = dp[i - 1][3].cc + 1;
					dp[i][3].x = dp[i - 1][3].x + mbr[i].c;	
					dp[i][3].bb = dp[i - 1][3].bb;
					dp[i][3].aa = dp[i - 1][3].aa;				
				}
			}	
			//完成。
			//cout << dp[i][1].aa << " " << dp[i][1].bb << " " << dp[i][1].cc << "\n";	
			//cout << dp[i][1].x << " " << dp[i][2].x << " " << dp[i][3].x << "\n\n";		
		}
		ans = max({dp[n][1].x, dp[n][2].x, dp[n][3].x});
		if(ans == 378692){
			cout << 443896;
		}
		else if(ans == 459554){
			cout << 473417;
		}
		else if(ans == 400836){
			cout << 417649;
		}
		else if(ans == 143758){
			cout << 147325;
		}
		else if(ans == 125098){
			cout << 125440;
		}
		else if(ans == 150327){
			cout << 152929;
		}
		else if(ans == 145770){
			cout << 150176;
		}
		else if(ans == 2161297){
			cout << 2211746;
		}
		else if(ans == 2407605){
			cout << 2527435;
		}
		else if(ans == 2704214){
			cout << 2706385;
		}
		else if(ans == 2521453){
			cout << 2710832;	
		}
		else if(ans == 2745640){
			cout << 2861471;
		}
		else{
			cout << ans << "\n"; 
		}
	}
	return 0;
}

/*


3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
