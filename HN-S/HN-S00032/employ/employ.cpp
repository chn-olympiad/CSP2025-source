#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
long long ans = 1;
long long rate=998244353;
int now;
int cnt_0 = 0;
int cnt_1 = 0;
int a[maxn];
int c[maxn];
bool c1[maxn];
int refuse[maxn];
int cmp[maxn];
int shiji(int start,int end){
	int num = 0;
	for(int i = start;i <= end;i++){
		if(c1[i]==0){
			num++;
		}
	}
	return num;
}
int quan(int k,int start,int t){
	int num=1;
	if(t==1){
		for(int i = start;i <= k;i++){
			num = num*(i-start+1)%rate;
		}
	}
	if(t==0){
		for(int i = start;i <= k;i++){
			num = num*(i-start+1)%rate;
		}
	}
	return num;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n , m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		a[i+1] = s[i] - '0';
		if(a[i+1]==1){
			cnt_1++;
			cmp[i+1] = cmp[i];
		}
		if(a[i+1]==0){
			cnt_0++;
			cmp[i+1] = cnt_0;
			refuse[cnt_0] = i + 1;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	int t = n - m;
	if(c[1]>t||cnt_1==n||m==1){
		for(int i = 1;i <= n;i++){
			ans = (i*ans)%998244353;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i = 1; i <= cnt_0;i++){
			int k = now+shiji(refuse[i-1]+1,refuse[i] - 1);
			if(k>=m){
				int jilu = 0;
				for(int i = refuse[i-1]+1;i<=refuse[i] - 1;i++){
					now++;
					if(now==m){
						jilu = i;
						break;
					}
					ans+=quan(n,jilu,0);
				}
				
			}
			else{
				ans+=quan(refuse[i]-1,refuse[i-1]+1,1);	
				now+=shiji(refuse[i-1]+1,refuse[i]-1);
				for(int j = refuse[i] + 1;j <= n;j++){
					if(c[j]<cmp[refuse[i]]){
						c1[i]=1;
					}
					if(c[j]>=cmp[refuse[i]]){
						break;
					}
				}
			}
		}
		cout<<ans;
		return 0;
}

return 0; 
}//3 2 101 1 1 2
//10 5 1101111011 6 0 4 2 1 2 5 4 3 3

