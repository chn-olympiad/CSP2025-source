#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]+0<=57 && s[i]+0>=48){
			a[s[i]+0-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	
	return 0;
}
//cout<<fixed<<setprecision(2)<<a;
//memset(a,0,sizeof(a));
//if(s.find(a)!=string::npos);
//__gcd(3,9)
//pow abs 
//map<string,int> m;
//a.substr(1,3);

//struct a{
//	int s;
//	string n;
//}b[100];
//bool cmp(a x,a y){
//	if(x.s==y.s) return x.n<y.n;
//	else return x.s>y.s;
//}

