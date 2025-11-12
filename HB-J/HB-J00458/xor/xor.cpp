#include<bits/stdc++.h>
using namespace std;

struct CSPJSAKNOIPAKNOIAKIOIAK{
	int start;
	int end;
	int x_len;
};

bool cmp(CSPJSAKNOIPAKNOIAKIOIAK CSPJSAKNOIPAKNOIAKIOIAK2026,CSPJSAKNOIPAKNOIAKIOIAK CSPJSAKNOIPAKNOIAKIOIAK2O26){
	return CSPJSAKNOIPAKNOIAKIOIAK2026.x_len<CSPJSAKNOIPAKNOIAKIOIAK2O26.x_len;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int dp[n];
	int num[n];
	for(int i=1;i<=n;i++){
		cin >> dp[i-1];
		num[i-1]=dp[i-1];
	}
	long long cnt=0;
	vector<CSPJSAKNOIPAKNOIAKIOIAK> out;
	for(int i=0;i<n;i++){
		if(dp[i]==k) out.push_back({i,i,0});
		for(int j=i+1;j<n;j++){
			dp[i]^=num[j];
			if(dp[i]==k) out.push_back({i,j,j-i});
		}
	}
	sort(out.begin(),out.end(),cmp);
	memset(num,0,sizeof(num));
	for(size_t i=0;i<out.size();i++){
		bool flag=false;
		for(int j=out[i].start;j<=out[i].end;j++){
			if(num[j]){
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(int j=out[i].start;j<=out[i].end;j++){
			num[j]=1;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
