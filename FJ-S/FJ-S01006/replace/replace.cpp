#include<bits/stdc++.h>
using namespace std;
const int long long N=2e5;
struct node{
	string s1;
	string s2;
}t[N+5];
long long n,q;
string sa,sb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>q;
	for (int i=1;i<=n;i++){
		cin >>sa>>sb;
		t[i].s1=sa;t[i].s2=sb;
	}
	for (int i=1;i<=q;i++){
		cin >>sa>>sb;
		int s=0;
		for (int i=1;i<=n;i++){
			if (sa==t[i].s1 && sb==t[i].s2){
				s++;
			}
		}
		if (s==0){
			cout <<0<<endl;
		}else{
			cout <<s+1<<endl;
		}
	}
	return 0;
}
