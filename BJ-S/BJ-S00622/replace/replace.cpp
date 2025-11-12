#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+19;
int q,n,cnt;
int kl1[maxn],kr1[maxn],kl2[maxn],kr2[maxn],kl[maxn],kr[maxn],bl1,br1,bl2,br2,bl,br;
void solve(){
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int ls1 = s1.size();
		int ls2 = s2.size();
		for(int j = 0;j<ls1;j++)
			if(s1[j] == 'b') kl1[i] = j;
		kr1[i] = ls1-kl1[i]-1;
		for(int j = 0;j<ls2;j++)
			if(s2[j] == 'b') kl2[i] = j;
		kr2[i] = ls2-kl2[i]-1;
		kl[i] = kl1[i]-kl2[i];
		kr[i] = kr1[i]-kr2[i];
	}
	for(int i = 1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int lt1 = t1.size();
		int lt2 = t2.size();
		for(int j = 0;j<lt1;j++)
			if(t1[j] == 'b') bl1 = j;
		br1 = lt1-bl1-1;
		for(int j = 0;j<lt2;j++)
			if(t1[j] == 'b') bl2 = j;
		br2 = lt2-bl2-1;
		bl = bl1-bl2;
		br = br1-br2;
		for(int i = 1;i<=n;i++){
			if(bl+kl[i] == 0 && br+kr[i] == 0) cnt++;
		}
	}
	cout<<cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t = 1;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
