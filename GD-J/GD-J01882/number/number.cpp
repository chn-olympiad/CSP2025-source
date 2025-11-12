#include<bits/stdc++.h>//100pts
#define ll long long 
using namespace std;
char x[1000005],S[1000005];
int tot,l,r;
bool f(char &x){
	return x>='0'&&x<='9'; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",S);
	tot=strlen(S);
	sort(S,S+tot);
	l=lower_bound(S,S+tot,'0')-S;
	r=upper_bound(S,S+tot,'9')-S;
	l=max(0,l-100);
	r=min(tot-1,r+100);
	while(!f(S[l]))l++;
	while(!f(S[r]))r--;
	for(int i=r;i>=l;i--)putchar(S[i]);
	return 0;
}
