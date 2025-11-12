#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

struct Node{
	int l,r;
};
vector<Node> b;
int a[500100],s[500100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0,last=0;
	bool _fA=1,_fB=1;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		s[i] = s[i-1]^a[i];
		if(a[i] != 1){
			_fA = 0;
		}
		if(a[i] > 1){
			_fB = 0;
		}
	}
	if(_fA){
		cout<<n/2;
		return 0;
	}
	if(_fB){
		if(k == 0){
			int _c = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					_c++;
				}else{
					c += _c/2;
					_c = 0;
				}
				c += a[i]==0;
			}
		}else{
			for(int i = 1; i <= n; i++){
				c += a[i]==1;
			}
		}
		cout<<c;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if((s[i]^s[j-1]) == k){
				b.push_back({j,i});
			}
		}
	}
	sort(b.begin(),b.end(),[](Node a,Node b){
		return a.r < b.r;
	});
	for(int i = 0; i < b.size(); i++){
		if(b[i].l > last){
			c++;
			last = b[i].r;
		}
	}
	cout<<c;
	return 0;
}
