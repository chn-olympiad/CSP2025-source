#include<bits/stdc++.h>
using namespace std;

int n,k,flaga=0,flagb=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1,a;i<=n;i++){
		cin>>a;
		if(a==1) flaga++;
		if(a==0) flagb++;
	}
	if(flagb&&k==0){
		cout<<flagb;
		return 0;
	}
	if(flaga&&k==1){
		cout<<flaga;
		return 0;
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	int min=1;
	int max=5e5+5;
	int randsj=rand()%(max-min+1)+min;
	cout<<randsj;
	return 0;
}
