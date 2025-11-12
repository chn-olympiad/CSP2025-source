#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int N[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	bool masp=1;
	for(int i=1;i<=n;i++){
		cin >> N[i];
		if(N[i] != 1)masp=0;
	} 
	//cout << 1;
	if(masp){
		unsigned long long ans=0;
		for(int i=3;i<=n;i++){
		    long long kans =1;
		    long long dels =n-i;
			if(dels == 0)dels=1;
			for(int j=0;j<i;j++){
				kans *= (n-j);
				if((dels != 0)&&(kans%dels == 0)){
					kans /= dels;
					dels-=1;
				}
			}
			ans = ((ans%p)+(kans%p))%p;
		}
		cout << ans;
		
		return 0;
	}

	return 0;
}
