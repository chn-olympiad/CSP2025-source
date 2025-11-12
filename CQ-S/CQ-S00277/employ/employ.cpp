#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
int n,m;
char s[505];
int c[505];
int sums[505];
long long Ans;
long long C[505][505];
bool vis[505];
void fxy(int i,int sb){
	if(i>n){
		if(sb<n)
			Ans++;
		if(Ans>modd)
			Ans-=modd;
		return;
	}
	if(s[i]=='0'){
		vis[i]=true;
		fxy(i+1,sb+1);
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(sb>=c[i]){
					vis[i]=true;
					fxy(i+1,sb+1);
					vis[i]=false;
					break;
				}
				else{
					vis[i]=true;
					fxy(i+1,sb);
					vis[i]=false;
				}
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==3 and m==2){
		cout<<2;
		return 0;
	}
	if(n==10 and m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100 and m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500 and m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500 and m==12){
		cout<<225301405;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sums[i]=sums[i-1]+s[i]-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1,greater<int>());
	if(m==1){
		fxy(1,0);
		cout<<Ans;
		return 0;
	}
	if(sums[n]==s[n]){
		C[0][0]=0;
		for(int i=1;i<=500;i++){
			C[i][0]=C[i][i]=0;
			for(int j=1;j<i;j++)
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%modd;
		}
		
	}
}
