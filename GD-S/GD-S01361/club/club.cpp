#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
struct node{
	int a;
	int b;
	int c;
	int delta;
};
bool cmp(node x,node y){
	return x.delta<y.delta;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin>>t;
	while(t--){
		int n;
		long long ans=0;
		int q=0,w=0,e=0;
		std::cin>>n;
		std::vector<node> a(n+1);
		std::vector<int> j;
		std::vector<int> k;
		std::vector<int> l;
		for(int i=1;i<=n;i++){
			std::cin>>a[i].a>>a[i].b>>a[i].c;
			int max=std::max({a[i].a,a[i].b,a[i].c});
			if(a[i].a==max){
				ans+=a[i].a;
				q++;
				int mmax=std::max(a[i].b,a[i].c);
				a[i].delta=max-mmax;
				j.push_back(a[i].delta);
			}
			else if(a[i].b==max){
				ans+=a[i].b;
				w++;
				int mmax=std::max(a[i].a,a[i].c);
				a[i].delta=max-mmax;
				k.push_back(a[i].delta);
			}
			else if(a[i].c==max){
				ans+=a[i].c;
				e++;
				int mmax=std::max(a[i].a,a[i].b);
				a[i].delta=max-mmax;
				l.push_back(a[i].delta);
			}
		}
		int maxn=n/2;
		int index=0;
		while(q>maxn){
			std::sort(j.begin(),j.end());
			ans-=j[index];
			index++;
			q--;
		}
		while(w>maxn){
			std::sort(k.begin(),k.end());
			ans-=k[index];
			index++;
			w--;
		}
		while(e>maxn){
			std::sort(l.begin(),l.end());
			ans-=l[index];
			index++;
			e--;
		}
		std::cout<<ans<<'\n';
	}
	return 0;
 } 
