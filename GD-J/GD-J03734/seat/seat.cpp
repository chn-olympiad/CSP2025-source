#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	int main(){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n,m;
		cin>>n>>m;
		int x;
		cin>>x;
		int cnt=0;
		for(int i=1;i<=n*m-1;i++){
			int y;
			cin>>y;
			if(y>x){
				cnt++;
			}
		}
		int s1 = cnt/n,s2;
		if(s1%2==0){
			s2 = cnt%n;
			cout<<s1+1<<' '<<s2+1;
		} 
		else{
			s2 = n-cnt%n;
			cout<<s1+1<<' '<<s2;
		}
		cout<<'\n';
		return 0;
	}
}
int main(){
	return my_space::main();
}

