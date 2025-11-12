#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+15;
int n,k,a[N],s[N],ans;
struct node{
	int l,r;
};
vector<node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int k=0;k<v.size();k++){
				if(i>=v[k].l&&i<=v[k].r||j>=v[k].l&&j<=v[k].r){
					flag=0;
					break;
				}
			}
			if(!flag) continue;
			if((s[j]^s[i-1])==k){
				ans++;
				v.push_back((node){i,j});
			}
		}
	}
	cout<<ans;
	return 0;
} 
