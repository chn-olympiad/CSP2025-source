#include <iostream>
#include <forward_list>
#include <cmath>
#include <algorithm>

using namespace std;

long n,m_a=0,m_b=0,m_c=0;

struct people{
	long long a;
	long long b;
	long long c;
}p[10005];

long f(long long x,long long i){
	if(i == n)return x;
	long long s_a=0,s_b=0,s_c=0;
	if(m_a < n/2){
		m_a++;
		s_a+=f(x+p[i].a,i+1);
		m_a--;
	}
	if(m_b < n/2){
		m_b++;
		s_b+=f(x+p[i].b,i+1);
		m_b--;
	}
	if(m_c < n/2){
		m_c++;
		s_c+=f(x+p[i].c,i+1);
		m_c--;
	}
	return max(s_a,max(s_b,s_c));
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin >> T;
	while(T--){
		cin >> n;
		for(long long i = 0;i < n;i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		cout << f(0,0) << endl;
	}
}
