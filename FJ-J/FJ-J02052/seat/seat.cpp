#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int b[200005];
int zuowei;
int ans;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
    std::cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xiaohua=a[1];
	sort(a+1,a+1+n*m);
	int paiming=0;
	for(int i=n*m;i>=1;i--){
//		cout<<a[i]<<'\n';
        paiming++;
		if(xiaohua==a[i]){
//			cout<<"   "<<xiaohua<<"   ";
			zuowei=paiming;
		
		}
	}
//	cout<<"--"<<zuowei<<"    ";
	for(int i=1;i<=m;i++){
		if(i%2){
				for(int j=1;j<=n;j++){
			ans++;
			if(ans==zuowei){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}
		else{
			for(int j=n;j>=1;j--){
				ans++;
				if(ans==zuowei){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	
	}
	return 0;
}//insert([]);
