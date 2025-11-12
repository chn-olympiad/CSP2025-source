#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6;
int a[3][N],m[3],you[3];
int bb[3][N];
struct node{
	int live;
	int order;
};
template<typename _Tp>
    struct cmp : public binary_function<_Tp, _Tp, bool>
    {
      bool
      operator()(const _Tp& x, const _Tp& y) const
      { return a[x.live][x.order] > a[y.live][y.order]; }
    };

priority_queue<node,vector<node>,cmp<node> >b[3];
queue<int> awa;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[0][j]>>a[1][j]>>a[2][j];
			if(a[0][j]>=a[1][j]&&a[0][j]>=a[2][j]){
				bb[0][j]=0;
				if(a[1][j]>=a[2][j]){
					bb[1][j]=1;
					bb[2][j]=2;
				}else{
					bb[1][j]=2;
					bb[2][j]=1;
				}
			}
			if(a[1][j]>=a[0][j]&&a[1][j]>=a[2][j]){
				bb[0][j]=1;
				if(a[0][j]>=a[2][j]){
					bb[1][j]=0;
					bb[2][j]=2;
				}else{
					bb[1][j]=2;
					bb[2][j]=0;
				}
			}
			if(a[2][j]>=a[1][j]&&a[2][j]>=a[0][j]){
				bb[0][j]=2;
				if(a[1][j]>=a[0][j]){
					bb[1][j]=1;
					bb[2][j]=0;
				}else{
					bb[1][j]=0;
					bb[2][j]=1;
				}
			}
			awa.push(j);
		}
		while(!awa.empty()){
			int i=awa.front();
			awa.pop();
			for(int k=0;k<=2;k++){
				if(b[bb[k][i]].size()>=n/2){
					int add=INT_MIN;
			    	for(int j=0;j<=2;j++){
		        		m[j]=a[j][i];
		        		you[j]=a[j][b[bb[k][i]].top().order];
		        		if(k!=j){
		        			add=max(add,you[j]-m[j]);
				    	}
		        	}
					if(m[bb[k][i]]+add>you[bb[k][i]]){
						awa.push(b[bb[k][i]].top().order);
						b[bb[k][i]].pop();
						node x;
						x.live=k;
						x.order=i;
						b[bb[k][i]].push(x);
						break;
					}else{
						continue;
					}
				}else{
					node x;
					x.order=i;
					x.live=k;
					b[bb[k][i]].push(x);
					break;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=2;i++){
			while(!b[i].empty()){
				ans+=a[i][b[i].top().order];
				b[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
