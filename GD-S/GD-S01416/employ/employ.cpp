#include<iostream>
#include<algorithm>
#include<string>
#define MOD 998244353
using namespace std;

string v;
int n,m,c[20],p[20],s[20],ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>v;
	for(int i=0;i<v.size();i++){
		s[i+1]=(int)(v[i]-'0');
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
		cin>>c[i];
	}
	
	do{
		int give_up=0,sum=0;
		for(int j=1;j<=n;j++){
			int i=p[j];
			if(give_up>=c[i] || s[j]==0){
				give_up++;
				continue;
			}
			else sum++;
			if(sum>=m){
				ans=(ans+1)%MOD;
				break;
			}
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<(ans+MOD)%MOD<<endl;
	return 0;
}
