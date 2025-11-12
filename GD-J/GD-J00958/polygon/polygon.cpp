#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans;
struct node{
	string s;
	int z=0,o=0,l=0;//z为0数，o为1数，l为长度 
}b;
void dfs(){
	if(n-b.l+b.o<3)return;
	if(b.l==n){
		int s=0,ma=-10086;
		string s1=b.s;
		for(int i=0;i<b.l;i++){
			if(s1[i]=='1'){
				s+=a[i+1];
				ma=max(ma,a[i+1]);
			}
		}
		if(s>ma*2){
			//cout<<s1<<endl;
			ans++;
			ans%=998244353;
		}
		return;
	}
	b.s[b.l]='1';
	b.l++;
	b.o++;
	dfs();
	b.s[b.l-1]=0;
	b.l--;
	b.o--; 
	b.s[b.l]='0';
	b.l++;
	b.z++;
	dfs();
	b.s[b.l-1]=0;
	b.l--;
	b.z--;
}
int main(){
	b.s="                                                                                                                                                                                                                                                         ";
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
