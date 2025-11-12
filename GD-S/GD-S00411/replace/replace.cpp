#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+13;

string s1[maxn];
string s2[maxn];
int n,ans=0;

void check(string a, string b){
	for(int i=1;i<=n;i++){
		if(a==s1[i] && b==s2[i]){
			ans++;
		}
	}
}

int main(){
	freopen("replace3.in","r",stdin);
	//freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int z=1;z<=q;z++){
		ans = 0;
		string t1,t2;
		cin >> t1 >> t2;
		
		check(t1, t2);
		
		int len = t1.size();
		string temp1;
		string temp2;
		
		int i=0,j=len-1;
		while(len > 0 && t1[i] == t2[i]){
			i++;
		}
		while(len > 0 && t1[j]==t2[j]){
			j--;
		}
		for(int k=i;k<=j;k++){
			temp1 += t1[k];
			temp2 += t2[k];
		}
		check(temp1, temp2);
		
		cout << ans << endl;
	}
	
	return 0;
	
} 
