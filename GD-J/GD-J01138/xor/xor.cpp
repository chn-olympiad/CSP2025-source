#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL K,num[500005],s[500005],x;
int ui=0,ans=0,N;
bool used[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>num[i];
		s[i]=s[i-1]^num[i];
	}
	
	for(int i=1;i<=N;i++){
		for(int j=ui;j<=i;j++){
			if(i>N){
				cout<<ans;
				return 0;
			}
			x=s[i]^s[j-1];
			if(x==K){
				ans++;
				ui=i+1;
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
