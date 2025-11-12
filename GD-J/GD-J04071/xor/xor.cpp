#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long nm[500004];

string chanA(long long x){
	long long N;
	string s;
	N = x;
	while(N > 0){
		string sm = to_string(N % 2);
		s += sm;
		N /= 2;
	}
	return s;
}//十转二 
long long chanB(string s){
	long long ans = 0;
	for(int i = 0;i < s.size();i ++){
		ans += (s[i] - '0') * pow(2,i);
	}
	return ans;
}//二转十
long long xo(long long a,long long b){
	string A = chanA(a);
	string B = chanA(b);
	string C = "";
	if(A.size() > B.size()){
		for(int i = B.size() + 1;i <= A.size();i ++){
			B += "0";
		}
	}
	if(A.size() < B.size()){
		for(int i = A.size() + 1;i <= B.size();i ++){
			A += "0";
		}
	}
	string Ans;
	for(int i = 0;i <= A.size();i ++){
		Ans = to_string(int(A[i] != B[i]));
		C += Ans;
	}
	return chanB(C);
}//异或代码 

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	nm[0] = 0;
	cin >> nm[1];
	for(int i = 2;i <= n;i ++){
		cin >> nm[i];
		nm[i] = xo(nm[i - 1],nm[i]);
	}
//	for(int i = 1;i <= n;i ++){
//		cout << nm[i] << " ";
//	}
//	cout << endl;
	long long r = 1,l = 0;
	long long ans = 0,pos;
	for(r = 1;r <= n;r ++){
		if(xo(nm[r],nm[l]) == k){
			ans ++;
			l = r;
			pos = l;
		}
		
	}
	r = n,l = n;
	for(l = n;l > pos;l --){
		if(xo(nm[r],nm[l]) == k){
			ans ++;
			r = l;
		}
	}
	cout << ans;
	return 0;
} 

