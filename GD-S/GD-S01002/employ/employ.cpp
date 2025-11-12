#include<iostream>
#include<vector>

using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,alive=0,dead=0;
	string dif;
	vector<int> p(n+1);
	scanf("%d%d",&n,&m);
	cin>>dif;
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
		if(p[i]<=dead){
			dead++;
		}else{
			alive++;
		}
	}
	//cout<<1;
	long long res=1;
	for(int i=1;i<=alive;i++){
		res%=998244353;
		res*=i;
	}
	printf("%lld",res);
}
