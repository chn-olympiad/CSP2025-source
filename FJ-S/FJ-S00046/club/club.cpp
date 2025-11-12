#include <bits/stdc++.h>
using namespace std;

int T,n,cnt1,cnt2,cnt3,a[100010],b[100010],c[100010];
long long ans;

priority_queue <pair <int,int>> q1,q2,q3;

void solve(){
	scanf("%d",&n);
	ans = 0;
	while(cnt1--){
		q1.pop();
	}
	while(cnt2--){
		q2.pop();
	}
	while(cnt3--){
		q3.pop();
	}
	cnt1 = cnt2 = cnt3 = 0;
	int num1,num2;
	for(int i = 1;i <= n;++i){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i] >= b[i] && a[i] >= c[i]){
			cnt1++;
			q1.push({max(b[i] - a[i],c[i] - a[i]),i});
			ans += a[i];
			if(cnt1 > n / 2){
				pair <int,int> num = q1.top();
				q1.pop();
				num1 = b[num.second] - a[num.second],num2 = c[num.second] - a[num.second];
				if(num1 >= num2){
					ans += num1;
					cnt2++;
					cnt1--;
					q2.push({max(-num1,num2 - num1),num.second});
				}else{
					ans += num2;
					cnt3++;
					cnt1--;
					q3.push({max(-num2,num1 - num2),num.second});
				}
			}
		}else if(b[i] >= a[i] && b[i] >= c[i]){
			cnt2++;
			q2.push({max(a[i] - b[i],c[i] - b[i]),i});
			ans += b[i];
			if(cnt2 > n / 2){
				pair <int,int> num = q2.top();
				q2.pop();
				num1 = a[num.second] - b[num.second],num2 = c[num.second] - b[num.second];
				if(num1 >= num2){
					ans += num1;
					cnt1++;
					cnt2--;
					q1.push({max(-num1,num2 - num1),num.second});
				}else{
					ans += num2;
					cnt3++;
					cnt2--;
					q3.push({max(-num2,num1 - num2),num.second});
				}
			}
		}else{
			cnt3++;
			q3.push({max(a[i] - c[i],b[i] - c[i]),i});
			ans += c[i];
			if(cnt3 > n / 2){
				pair <int,int> num = q3.top();
				q3.pop();
				num1 = a[num.second] - c[num.second],num2 = b[num.second] - c[num.second];
				if(num1 >= num2){
					ans += num1;
					cnt1++;
					cnt3--;
					q1.push({max(-num1,num2 - num1),num.second});
				}else{
					ans += num2;
					cnt2++;
					cnt3--;
					q2.push({max(-num2,num1 - num2),num.second});
				}
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
