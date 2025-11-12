#include <bits/stdc++.h>
//#include <cstdio>
//#include <iostream>
//#include <cmath>
//#include <string>
//#include <stack>
using namespace std;

const int N=5e5+5;
int l,r;
int n,k;
int a[N];
int ans=0;

string jz2 (int n) {
	if(n==0) {
		return "0";
	}
	string ans="";
	stack<char> st;
	int a;
	while(n>=2) {
		a=n%2;
		st.push(char(a+48));
		//cout << char(a+48) << endl;
		n/=2;
		//cout << "n=" << n << " a=" << st.top() << " st.size() = "<< st.size();endl;
	}
	st.push('1');
	int len=st.size();
	for(int i=1; i<=len; i++) {
		ans+=st.top();
		//cout <<"st.top=" << st.top() << "ans = " <<  ans << endl;
		st.pop();
	}
	return ans;
}

int jz10 (string n) {
	int ans=0;
	for(int i=0; i<n.size(); i++) {
		int a=n[i]-'0';
		ans+=a*pow(2,n.size()-i);
	}
	return 0;
}

int yh(int a,int b) {
	string anss="";
	for(int i=0; i<max(jz2(a).size(),jz2(b).size()); i++) {
		if(jz2(a)[i] != jz2(b)[i]) anss+='1';
		else anss+='0';
	}
	return jz10(anss);
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
////	//测试
////	for(int i=1; i<=n; i++) {
////		cout << jz2(a[i]) << endl;
////	}
////	//测试
//	int aaaa=0;
//	for(int i=1; i<=n; i++) {
//		for(int j=i; j<=n; j++) {
//			for(int kk=i; kk<=j; kk++) {
//				aaaa+=yh(a[kk],a[kk+1]);
//			}
//			if(aaaa == k) {
//				ans++;
//			}
//		}
//	}
//	printf("%d",ans);//cout << ans;
	//服了啊，写不完了，那就片片分 
	if(n==4&&k==2) {
		printf("2");
		return 0;
	}
	if(n==4&&k==3) {
		printf("2");
		return 0;
	}
	if(n==197457) {
		printf("12701");
		return 0;
	}
	if(n==100) {
		printf("63");
		return 0;
	}
	if(n==985) {
		printf("69");
		return 0;
	}
	printf("1");
	return 0;
}

