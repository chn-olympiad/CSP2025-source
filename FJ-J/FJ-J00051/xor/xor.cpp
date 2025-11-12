#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 5e5+5;
int h[MAXN] = {}, qz[MAXN] = {};
struct number{
	int num, ni;
}nums[MAXN];

bool cmp(number a, number b){
	return a.num == b.num?a.ni<b.ni:a.num<b.num;
}

int find(int l, int r, int tar, int tari){
	int mid, ans = -1;
	while(l <= r){
		mid = (r-l)/2+l;
		if(nums[mid].num < tar){
			l = mid+1;
		}
		else if(nums[mid].num > tar){
			r = mid-1;
		}
		else{
			if(nums[mid].ni >= tari){
				r = mid-1;
			}
			else{
				l = mid+1;
				ans = mid;
			}
		}
	}
	return ans;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	int n, k, thg = -1;
	scanf("%d %d", &n, &k);
	for(int i= 1; i<=n; i++){
		scanf("%d", &h[i]);
		qz[i] = qz[i-1]^h[i];
	}
	for(int i = 1; i<=n; i++){
		nums[i].num = qz[i];
		nums[i].ni = i;
	}
	
	sort(nums+1, nums+n+1, cmp);

	int q = 0, cnt = 0;
	for(int i = 1; i<=n; i++){
		if(qz[i] == k && q == 0){
			q = i;
			cnt++;
			continue;
		}
		thg = find(1, n, qz[i]^k, i);
		if(thg != -1 && nums[thg].ni >= q && i != nums[thg].ni){
			cnt++;
			q = i;
		}
	}
	printf("%d", cnt);
	return 0;
}

