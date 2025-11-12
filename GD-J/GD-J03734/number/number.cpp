#include<bits/stdc++.h>
using namespace std;
namespace my_space{
	using ll = long long;
	int cmp(int a,int b){
		return a>b;
	}
	constexpr int N = 1e6+50;
	int a[N],tot;
	int main(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		string s;
		cin>>s;
		for(auto c:s){ 
			if(c>='0' && c<='9'){
				a[++tot] = (c^48);
			}
		}
		sort(a+1,a+1+tot,cmp);
		for(int i=1;i<=tot;i++){
			cout<<a[i];
		}
		cout<<'\n';
		return 0;
  }
}
int main(){
	return my_space::main();
}

