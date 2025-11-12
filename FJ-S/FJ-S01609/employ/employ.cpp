#include<iostream>
using namespace std;
const int MAXN=505;
int a[MAXN];
string s;
bool flag1=1,flag2=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int N=s.size();
	for(int i=0;i<N;i++){
		a[i]=s[i]-'0';
		if(s[i]!=0)flag1=0;
		if(s[i]!=1)flag2=0;
	}
	if(flag1){
		if(m==n){
			int res=1;
			for(int i=1;i<=n;i++){
				res=res*i;
				res%=998244353;
			}
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
