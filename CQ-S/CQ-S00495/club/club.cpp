#include<bits/stdc++.h>
using namespace std;
namespace jsk{
	int t,n,sum;
	struct node{
		int a,b,c;
		int cha_a_b;
		int cha_a_c;
		int cha_b_c;
		int id;
	}vis[100005],jl[100005]; 
	bool cmp(node x,node y){
		return x.cha_a_b>y.cha_a_b;
	}
	bool cmp1(int x,int y){
		return vis[x].cha_a_c>vis[y].cha_a_c;
	}
	bool cmp2(int x,int y){
		return vis[x].cha_b_c>vis[y].cha_b_c;
	}
	vector<int> a,b,c;
	int main(){
//		freopen("club.in","r",stdin);
//		freopen("club.out","w",stdout);
		cin >> t;
		for(int l=1;l<=t;l++){
			cin >> n;
			sum=0;
			while(a.size()){
				a.pop_back();
			}
			while(b.size()){
				b.pop_back();
			}
			while(c.size()){
				c.pop_back();
			}
			for(int i=1;i<=n;i++){
				cin >> vis[i].a >> vis[i].b >> vis[i].c;
				vis[i].cha_a_b=abs(vis[i].a-vis[i].b);
				vis[i].cha_a_c=vis[i].c-vis[i].a;
				vis[i].cha_b_c=vis[i].c-vis[i].a;
				jl[i].a=vis[i].a;
				jl[i].b=vis[i].b;
				jl[i].c=vis[i].c;
				jl[i].cha_a_b=vis[i].cha_a_b;
				jl[i].id=i;
			} 
			sort(jl+1,jl+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(jl[i].a>=jl[i].b){
					a.push_back(jl[i].id);
				}
				else{
					b.push_back(jl[i].id);
				}
			}
			sort(a.begin(),a.end(),cmp1);
			sort(b.begin(),b.end(),cmp2);
//			for(int i=0;i<a.size();i++){
//				cout << a[i] << " ";
//			} 
//			cout << endl;
//			for(int j=0;j<b.size();j++){
//				cout << b[j] << " ";
//			}
//			cout << endl;
			int i=0,j=0;
			while(i<a.size()&&j<b.size()&&vis[a[i]].cha_a_c>0&&vis[b[j]].cha_b_c>0){
				if(vis[a[i]].cha_a_c>=vis[b[j]].cha_b_c){
					c.push_back(a[i]);
					sum+=vis[a[i]].c;
					i++;
				}
				else{
					c.push_back(b[i]);
					sum+=vis[b[i]].c;
					j++;
				}
				if(c.size()==n/2){
					break;
				}
			}
			if(!c.empty()){
				if(c.size()!=n/2){
					while(i<a.size()&&vis[a[i]].cha_a_c>0){
						c.push_back(a[i]);
						sum+=vis[a[i]].c;
						i++;
					}
					while(j<b.size()&&vis[b[j]].cha_b_c>0){
						c.push_back(b[i]);
						sum+=vis[b[i]].c;
						j++;
					}
				}
			}
			while(i<a.size()){
				sum+=vis[a[i]].a;
				i++;
			}
			while(j<b.size()){
				sum+=vis[b[i]].b;
				j++;
			}
			cout << sum << endl;
		}


		return 0;
	}
}
int main(){
	return jsk::main();
}

