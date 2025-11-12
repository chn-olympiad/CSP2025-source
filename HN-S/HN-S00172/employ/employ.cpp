#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=500, mod=998244353;
bool s[N];//难度 
string s1;
int c[N];//耐心 
struct pm{
	int local=0;
	int sum=0;
	int far=0;//不包括“0”的长高度
	//void cf(){far=part[local].local-part[local-1].local-1;}
}part[N];
int pz=1;
//vector<pm> part;
void begin(){
	for(int i=1;i<=n;i++){
		if(!s[i]){
			part[pz].local=i;
			part[pz].far=i-part[pz-1].local-1;
		}
	}
	for(int i=1;i<=n;i++)part[c[i]].sum++;
}
void think(){
	
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)s[i]=s1[i-1]=='1';
	begin();
	return 0;
}
