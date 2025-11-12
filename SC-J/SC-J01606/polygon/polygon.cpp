#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5+5,p = 998244353;
long long i,j,n,m,k,l,x,y,a[N],s[N],flag,cnt;
map<long long,long long> ma;
map<long long,long long>::iterator q;
vector<long long> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	flag = 1;
	for(i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != 1)flag = 0;
	}
	if(flag){
		cout <<(n-2)*(n-1)/2;
		return 0;
	}
	sort(a+1,a+n+1);
	for(i = 1;i <= n;i ++){
		s[i] = s[i-1]+a[i];
	}
	
	cnt = 0;
	long long cu = 1;
	ma[a[1]+a[2]] ++;
	for(i = 3;i <= n;i ++){
		v.clear();
		for(q = ma.begin();q != ma.end();q ++){
			x = q->second;
			while(x --)v.push_back(q->first + a[i]);
		}
		for(j = 1;j < i;j ++)v.push_back(a[i]+a[j]);
		for(j = 0;j < v.size();j ++)ma[v[j]] ++;
		x = 2*a[i];
		for(j = x+1;j <= s[i];j ++){
			if(ma.find(j) != ma.end()){
				cnt = (cnt+ma.find(j)->second)%p;
			}
		}
	}
	cout << cnt;
	return 0;
}