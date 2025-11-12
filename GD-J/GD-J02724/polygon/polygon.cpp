#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
ll n,a[N],ans,cnt,b[N];
bool c(){
	int cl=0,ml=0;
	if(cl>ml*2) return 1;
	else return 0;
}
void f(int s,int g){
	if(cnt==g){
		if(c()==1) ans++;
	}
	else{
		
	}
}
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin>>n;
	for(int i=1;i<=n;i++) fin>>a[i];
	for(int i=3;i<=n;i++){
		f(1,i);
	}
	ans%=998244353;
	fout<<ans;
} 
