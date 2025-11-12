#include<bits/stdc++.h>
using namespace std;
int b[1010][1010];
int k,n,a[500010],cnt=0; 
struct node{
	int l,r;
};
vector<node>v; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
        b[i][i] = a[i]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[i][j] =max(b[i][j],b[i][j-1]^a[j]);
			if(b[i][j] == k){
				int flag = 0;
				for(int i=0;i<v.size();i++){
					if((i<=v[i].l&&v[i].l<=j)||(i<=v[i].r&&v[i].r<=j))flag = 1; 
				} 
				if(!flag){
					cnt++;
					v.push_back({i,j});
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
