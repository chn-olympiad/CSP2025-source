#include <string>
#include <iostream>
#include <algorithm>

const long long MAX = 5e2+5;
const long long MOD = 998244353;

long long n,m;
std::string s;
long long c[MAX];
bool flag = true,vis[MAX];
long long cnt = 0,person = 0;
long long p[MAX];

bool check(long long x){
	long long temp = 0,cnt = 0;
	
	for(long long i=0;i < x;++i)
		if(temp < c[p[i]])
			if(s.at(i) == '1')	++cnt;
			else	++temp;
		else	++temp;
	
	return m <= cnt;
}

void dfs1(long long step){
	if(step == n){
		if(check(n))	++cnt;
		cnt%=MOD;
		return;
	}
	
	for(long long i=0;i < n;++i){
		if(!vis[i]){
			vis[i] = true;
			p[step] = i;
			
			dfs1(step+1);
				
			vis[i] = false;
		}
	}
	
	return;
}

void dfs2(long long step){
	if(step == n){
		if(check(n))	++cnt;
		cnt%=MOD;
		return;
	}
	
	for(long long i=0;i < n;++i){
		if(!vis[i]){
			vis[i] = true;
			p[step] = i;
			
			if(check(step+1)){
				++cnt;
				cnt%=MOD;
				return;
			}
			dfs2(step+1);
				
			vis[i] = false;
		}
	}
	
	return;	
}

int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	
	std::cin >> n >> m;
	std::cin >> s; 
	
	for(long long i=0;i < n;++i)	std::cin >> c[i];
	
	for(size_t i = 0;i < n;++i)
		if(s.at(i) == '1')	++person;
	
	if(person < m)	std::cout << 0;
	else if(n <= 10){
		dfs1(0);
		std::cout << cnt;
	}else if(m == n){
		std::sort(c,c+n);
		
		for(long long i=0;i < n;++i){
			cnt*=std::max((c[i] - i),(long long)0);
			cnt%=MOD;
		}
		
		std::cout << cnt;
	}else if(person == n){
		cnt = 1;
		for(long long i=1;i <= n;++i){
			cnt*=i;
			cnt%=MOD;
		}
		
		std::cout << cnt;
	}else{
		dfs2(0);
		std::cout << cnt;
	}
	
	fclose(stdin);
	fclose(stdout);
	
    return 0;
}