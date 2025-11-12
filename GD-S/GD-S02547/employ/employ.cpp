#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int m,n,pation[N],sum,in[N],at[N];
bool pass[N],used[N];
map<string,bool>mp;
string to(int i[]){
	string ans = "";
	for(int c = 0;c < n;c++){
		string a = "";
		at[c] = in[c];
		if(i[c] == 0){
			ans += "0 ";
			continue;
		}
		while(i[c]){
			a += char(i[c] % 10 + 48);
//			cout << a << "---" << i[c] << '\n';
			i[c] /= 10;
		}
		ans += a + ' ';
	}
	return ans;
}
void DFS(int f,int cnt,int left){
	if(f == n){
//		cout << cnt << ' ' << left << '\n';
		sort(in,in + n);
		string str = to(in);
//		cout << str << '\n';
//		for(int i = 0;i < n;i++){
//			cout << at[i] << ' ';
//		}cout << '\n';
		if(mp[str])return;
		else {
			mp[str] = 1;
		}
		if(cnt >= m){
			sum++;
		}
		return;
	}
	for(int i = 0;i < n;i++){
		if(used[i])continue;
		used[i] = 1;
		if(pation[i] <= left){
			in[f] = 1e9;
			DFS(f + 1,cnt,left + 1);
		}else if(pass[f] == 0){
			in[f] = 1e9;
			DFS(f + 1,cnt,left + 1);
		}else{
			in[f] = i;
			DFS(f + 1,cnt + 1,left);
		}
		used[i] = 0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(int i = 0;i < n;i++){
		char c = getchar();
		if(c == '1'){
			pass[i] = 1;
		}else{
			pass[i] = 0;
		}
	}for(int i = 0;i < n;i++){
		scanf("%d",&pation[i]);
	}
	DFS(0,0,0);
	printf("%d",sum);
	return 0;
} 
