#include<bits/stdc++.h>
using namespace std;

int n,m;
bool ch[505];
int c[505]; 
bool flag[505];
string str;
long long ans;

long long run(int k, long long giveup, long long now){
	if(k==n){
		if(now+1>=m){
			++ans;
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		if(!flag[i]){
			flag[i]=true;
			cout<<i<<endl;
			if(ch[k]==0||giveup>c[i]){
				run(k+1, giveup+1, now);
			}
			else{
				run(k+1, giveup, now+1);
			}
			flag[i]=false;
		}
	}
	return 0;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>str;
	for(int i=0;i<n;i++){
		ch[i]=(str[i]-'0');
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	run(0, 0, 0);
	cout<<ans;
	return 0;
}
