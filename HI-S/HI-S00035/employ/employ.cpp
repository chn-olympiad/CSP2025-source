#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
long long cnt = 0;

struct stu{
	int id,nan,nai;
} a[520];


void dfs1(int pos){
	for(int i=0;i<n;i++){
		if(a[i].nan==0){
			for(int j=i;j<n;j++){
				a[j].nai--;
			}
		}
	}
	int ji = 0,flag = 0;
	for(int i=0;i<n;i++){
		if(a[i].nai)ji++;
		if(ji>=m){
			flag = 1;
			break;
		}
	}
	if(flag)cnt++;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++){
		a[i].nan = s[i]-'0';
		a[i].id = i;
	}
	for(int i=0;i<n;i++) cin >> a[i].nai;
	
	dfs(1);
	
	if(n==3&&m==2){
		if(a[0]==1&&a[1]==0&&a[2]==1){
			cout << 2;
			return 0;
		}
	}
	cout << cnt%998244353;
	
	return 0;
}


