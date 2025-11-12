#include<bits/stdc++.h>
using namespace std;
int n, k, a[(1 << 20) + 5], b[(1 << 20) + 5];
vector<pair<int, int> > v;
long long cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int maxa = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
		b[i] = b[i-1]^a[i];
		//cout << b[i] << ' ';
	}
	if(maxa<=1){
		if(k = 1){
			for(int i = 1; i <= n; i ++)
			{
				cnt += a[i];
			}
			cout << cnt << endl;
		}
		else{
			for(int i = 1; i <= n; i ++){
				if(a[i]==0)cnt++;
				if(a[i]==1||a[i+1]==1){
					cnt++;
					i++;
				}
			}
			cout << cnt << endl;
		}
		return 0;
	}
	//cout << endl;
	for (int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++){
			if(abs(b[j]-b[i-1])==k)v.push_back(make_pair(j, i));
		}
	}
	sort(v.begin(), v.end());
	cnt = 1;
	pair<int, int> lst = v[0];
	for(int i = 1; i < v.size(); i ++){
		if(v[i].second>lst.first){
			cnt++;	
			lst=v[i];
		//cout << v[i].second <<' ' <<v[i].first<<endl;
		}
	}
	cout << cnt;
	return 0;
}
