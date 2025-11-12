#include<bits/stdc++.h>
using namespace std;
string b;
int cnt[1000001];
char c;
int num;
int shu=1;int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,b);
	n=b.length();
	for(int i=0;i<=n;i++){
		if('0'<=b[i] && b[i]<='9'){
			cnt[shu]=b[i]-'0';
			shu++;
		}
	}
	sort(cnt+1,cnt+shu);
	for(int i=shu-1;i>=1;i--) cout<<cnt[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
