#include<bits/stdc++.h>

using namespace std;

constexpr int N = 500005;

bool cmp(pair<int , int> a , pair<int , int> b)
{
	if(a.second < b.second)
	{
		return true;
	}
	else if(a.second == b.second)
	{
		if(a.first > b.first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int pref[N];
int arr[N];
//priority_queue<pair<int , int> , vector<pair<int , int> > > ranges;
vector<pair<int , int> > ranges;
pair<int , int> nul;

int n , k;

int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n>>k;

	ranges.assign(1000005 , nul);

	for(int i = 1 ; i <= n ; i++)
	{
		cin>>arr[i];
		pref[i] = pref[i - 1] ^ arr[i];
	}

	long long cnt = 0;
	long long ranges_cnt = 0;
	for(int l = 1 ; l <= n ; l++)
	{
		for(int r = l ; r <= n ; r++)
		{
			if((pref[r] ^ pref[l - 1]) == k)
			{
				ranges[ranges_cnt ++] = {l , r};
				//cerr<<"t: "<<l<<" "<<r<<" "<<(pref[r] ^ pref[l - 1])<<"\n";
			}
		}
	}
	//cerr<<ranges_cnt<<" \n";
	sort(ranges.begin() , ranges.begin() + ranges_cnt , cmp);

	// for(int i = 0 ; i <= ranges_cnt ; i++)
	// {
	//  	cerr<<ranges[i].first<<" "<<ranges[i].second<<"\n";
	// }

	int vl = 0 , vr = 0;
	for(int i = 0 ; i < ranges.size() ; i++)
	{
		pair<int , int> range = ranges[i];
		int l = range.first , r = range.second;
		if(vr < l)
		{
			vr = r;
			cnt++;
		}
	}

	cout<<cnt;
	return 0;
} 