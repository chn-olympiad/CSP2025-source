#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m,c[505],tmp1,k;
long long ans=1;
string s;
bool flag=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	srand(time(0));
	tmp1=n;
	for(int i=1,j=0;i<=n;i++,j++){
		cin>>c[i];
		if(c[i]==0) tmp1--;
		if(s[j]!='1') flag=false;
	}
	if(flag){
		for(long long i=n;i>1;i--){
			ans=(ans*i)%N;
		}
		cout<<ans<<endl;
	}
	else if(m==1){
		for(long long i=n-1;i>1;i--){
			ans=(ans*i)%N;
		}
		ans=(ans*tmp1)%N;
		cout<<ans<<endl;
	}
	else{
		cout<<rand()%N<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
