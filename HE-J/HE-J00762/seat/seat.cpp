#include<bits/stdc++.h>
using namespace std;
int s[105],MAP[105][105],re;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<n<<' '<<m;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int rgoal=s[1];//Ð¡R·ÖÊý
	int re;
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(s[i]<s[j]){
				swap(s[i],s[j]);
			}
			if(s[i]==rgoal){
				re=i;
			}
		}
	}
	if(re<=n){
		cout<<'1'<<' '<<re;
		return 0;
	}
	int k=0;
	int l=n*m;
	while(l--){
		k++;
		int tk=0;
		for(int j=1;j<=m;j++){
			if(k%2!=0){
				for(int i=1;i<=n;i++){
					tk++;
					if(s[tk]==re){
						cout<<j<<' '<<i;
						return 0;
					}
				}
			}
			else{
				for(int i=n;i>=1;i--){
					tk++;
					if(s[tk]==re){
						cout<<j<<' '<<i;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
