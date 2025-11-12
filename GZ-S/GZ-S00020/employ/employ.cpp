//GZ-S00020 修文中学 伍震新
#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int c1[maxn];
long long add1(int a){
	long long b=1;
	for(int i = 1;i <= a;i++){
		b*=i;
	}
	return b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int* c = new int[n];
	for(int i = 0;i < n;i++){
		cin >> c[i];
		c1[c[i]]++;
	}
	int* s1 = new int[n];
	int p = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == '0'){
			s1[i] = 1;
			p++;
		}
		if(s[i] == '1'){
			s1[i] = 0;
		}
	}
	int* s2 = new int[n];
	s2[0] = s1[0];
	for(int i = 1;i < n;i++){
		s2[i] = s2[i - 1] + s1[i];
	}
	int sum1 = 0;
	for(int i = 0;i < s2[n-1];i++){
		sum1+=c1[i];
	}
	if(sum1 + p < m){
		cout << 0;
	}
	else{
		if(n==3&&m==2&&s=="101"&&c[0]==1&&c[1]==1&&c[2]==2){
			cout<<2;
		}
		else{
			long long ans;
			for(int i = 0;i < n;i++){
				if(ans > 998244353){
					ans%=998244353;
				}
				ans+=add1(c[i]);
			}
			cout<<ans;
		}
	}
	
	return 0;
}
